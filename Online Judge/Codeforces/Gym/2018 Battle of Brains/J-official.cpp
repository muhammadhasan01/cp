#include <bits/stdc++.h>

using namespace std;

struct player
{
    string name;
    int att, def;
    player() {}
    player(string name, int att, int def): name(name), att(att), def(def) {}
};

struct profile
{
    string name;
    int att, def, win, loss;
    int score;
    bool retired;
    vector < pair<string, int> > v; ///tournament by tournament result
    void init(string _name, int _att, int _def)
    {
        name = _name;
        att = _att;
        def = _def;
        score = retired = win = loss = 0;
    }
    bool operator < (const profile &p) const
    {
        if( retired == p.retired )
        {
            if( score == p.score ) return name < p.name;
            else return score > p.score;
        }
        else
        {
            if( retired == false ) return true;
            else return false;
        }
    }
    void show(int rnk)
    {
        cout << name << "\n";
        printf("att     : %d\n", att);
        printf("def     : %d\n", def);
        printf("retired : ");
        if( retired ) puts("yes");
        else puts("no");
        if( retired ) printf("rank    : -\n");
        else          printf("rank    : %d\n", rnk);
        if( retired ) printf("score   : -\n");
        else printf("score   : %d\n", score);
        int cnt = 0;
        for(int i = 0; i < v.size(); i++) if( v[i].second == 1 ) cnt++;
        printf("title   : %d\n", cnt);
        printf("win-loss: %d-%d\n", win, loss);
    }
};
vector <profile> atp;

void add_score(string t_name, int k, string name, int pos)
{
    for(int i = 0; i < atp.size(); i++)
    {
        if( atp[i].name == name )
        {
            assert( atp[i].retired == false );
            atp[i].win += (k - pos);
            if( pos ) atp[i].loss++;
            atp[i].score += (1 << (k - pos));
            atp[i].v.push_back( make_pair(t_name, 1 << pos) );
            break;
        }
    }
}

void reduce_score(string name, int x)
{
    for(int i = 0; i < atp.size(); i++)
    {
        if( atp[i].name == name )
        {
            atp[i].score -= x;
            return;
        }
    }
    assert(false);
}

struct history
{
    string t_name;
    int k; ///level
    ///player, level reached
    map <string, int> mp;
    void add(string name, int pos)
    {
        assert( mp.find(name) == mp.end() );
        mp[name] = pos;
        add_score(t_name, k, name, pos);
    }
    void reduce()
    {
        map <string, int> :: iterator it;
        it = mp.begin();
        int cnt = 0;
        while( 1 )
        {
            if( it == mp.end() ) break;
            cnt++;
            string name = it->first;
            int pos = it->second;
            reduce_score(name, 1 << (k - pos));
            it++;
        }
        if( k ) assert( cnt == (1 << k) );
    }
    void init(int _k)
    {
        reduce();
        k = _k;
        mp.clear();
    }
};
map <string, history> t_history;

int cur_rand;
int multiplier = 1000075057;
int adder = 1000099999;
int modder = 1088888881;
void gen_next_rand()
{
    cur_rand = ( (long long)cur_rand * multiplier + adder ) % modder;
}
bool point_simulator(player p1, player p2) ///server, receiver
{
    gen_next_rand();
    int p = 50 + p1.att - p2.def;
    int r = cur_rand % 100;
    return r < p;
}

int game_simulator(player p1, player p2, int &server) ///server, receiver
{
    server ^= 1;
    int a = 0;
    int b = 0;
    while( 1 )
    {
        if( a >= 4 && a - b >= 2 ) return 1;
        if( b >= 4 && b - a >= 2 ) return 0;
        bool f = point_simulator(p1, p2);
        if( f ) a++;
        else b++;
    }
}

int set_simulator(player p1, player p2, int &server) ///player1, player2
{
    int a = 0;
    int b = 0;
    while( 1 )
    {
        if( a >= 6 && a - b >= 2 ) return 1;
        if( b >= 6 && b - a >= 2 ) return 0;
        int f;
        if( server == 0 ) f = game_simulator(p1, p2, server);
        else f = game_simulator(p2, p1, server) ^ 1;
        if( f ) a++;
        else b++;
    }
}

map < pair<string, string> , int > h2h;

void head_to_head(player p1, player p2)
{
    string a = p1.name;
    string b = p2.name;
    if( h2h.find( make_pair(a, b) ) == h2h.end() ) h2h[ make_pair(a, b) ] = h2h[ make_pair(b, a) ] = 0;
    h2h[ make_pair(a, b) ]++;
}

int match_simulator(player p1, player p2, int set_count)
{
    int win = (set_count + 1) / 2;
    int server = 0;
    int a = 0;
    int b = 0;
    while( 1 )
    {
        if( a == win )
        {
            head_to_head(p1, p2);
            return 1;
        }
        if( b == win )
        {
            head_to_head(p2, p1);
            return 0;
        }
        int f = set_simulator(p1, p2, server);
        if( f ) a++;
        else b++;
    }
}

vector <int> gen_draw(int k)
{
    int level = 0;
    vector <int> v;
    v.push_back( 1 );
    while( 1 )
    {
        level++;
        int need = (1 << level) + 1;
        vector <int> tmp;
        for(int i = 0; i < v.size(); i++)
        {
            tmp.push_back( v[i] );
            tmp.push_back( need - v[i] );
        }
        v = tmp;
        if( level == k ) return v;
    }
}

vector <int> tournament_simulator(vector <player> p, int k, int set_count)
{
    assert( p.size() == (1 << k) );
    map <string, int> mp;
    for(int i = 0; i < p.size(); i++) mp[ p[i].name ] = i;
    vector <int> result(1 << k, 0);

    vector <int> v = gen_draw(k);
    vector <player> cur;
    for(int i = 0; i < v.size(); i++) cur.push_back( p[ v[i] - 1 ] );

    int level = k;
    while( 1 )
    {
        assert( cur.size() == (1 << level) );
        for(int i = 0; i < cur.size(); i++)
        {
            int idx = mp[ cur[i].name ];
            result[idx] = level;
        }
        if( level == 0 ) return result;

        vector <player> tmp;
        for(int i = 0; i < cur.size(); i += 2)
        {
            int f = match_simulator(cur[i], cur[i+1], set_count);
            if( f ) tmp.push_back( cur[i] );
            else tmp.push_back( cur[i+1] );
        }
        cur = tmp;
        level--;
    }
}

void play_tournament(string name, int k, int set_count, int rnk)
{
    if( t_history.find( name ) == t_history.end() )
    {
        history tmp;
        tmp.t_name = name;
        tmp.k = 0;
        tmp.mp.clear();
        t_history[name] = tmp;
    }
    history &my = t_history[name];
    my.init(k);

    vector <player> p;
    assert( rnk + (1 << k) <= atp.size() );
    for(int i = rnk, j = 0; j < (1 << k); i++, j++)
    {
        assert( atp[i].retired == false );
        p.push_back( player( atp[i].name, atp[i].att, atp[i].def ) );
    }

    vector <int> result = tournament_simulator(p, k, set_count);
    for(int i = 0; i < p.size(); i++)
    {
        my.add( p[i].name, result[i] );
    }
    sort( atp.begin() , atp.end() );

    cout << "played " << name << "\n";
}

void show_profile(string name)
{
    for(int i = 0; i < atp.size(); i++)
    {
        if( atp[i].name == name )
        {
            atp[i].show(i + 1);
            return;
        }
    }
    assert(false);
}

void show_standings()
{
    for(int i = 0; i < atp.size(); i++)
    {
        if( atp[i].retired ) break;
        cout << i + 1 << ". " << atp[i].name << " " << atp[i].score << "\n";
    }
}

void show_head_to_head(string a, string b)
{
    int cnt = 0;
    for(int i = 0; i < atp.size(); i++) if( atp[i].name == a ) cnt++;
    for(int i = 0; i < atp.size(); i++) if( atp[i].name == b ) cnt++;
    assert( cnt == 2 );
    assert( a != b );

    if( h2h.find( make_pair(a, b) ) == h2h.end() )
    {
        cout << a << " 0 : 0 " << b << "\n";
    }
    else
    {
        int x = h2h[ make_pair(a, b) ];
        int y = h2h[ make_pair(b, a) ];
        cout << a << " " << x << " : " << y << " " << b << "\n";
    }
}

void add_player(string name, int att, int def)
{
    for(int i = 0; i < atp.size(); i++) assert( atp[i].name != name );

    profile tmp;
    tmp.init(name, att, def);
    atp.push_back( tmp );
    sort( atp.begin() , atp.end() );
    cout << "added " << name << "\n";
}

void remove_player(string name)
{
    for(int i = 0; i < atp.size(); i++)
    {
        if( atp[i].name == name )
        {
            atp[i].retired = 1;
            sort( atp.begin() , atp.end() );
            cout << "retired " << name << "\n";
            return;
        }
    }
    assert( false );
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T;
    char ins[15];
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        scanf("%s", ins);
        if( strcmp(ins, "add") == 0 )
        {
            string name;
            int att, def;
            cin >> name >> att >> def;
            assert( name.size() <= 10 );
            assert( 70 <= att && att <= 90 );
            assert( 60 <= def && def <= 90 );
            assert( def <= att );
            add_player(name, att, def);
        }
        else if( strcmp(ins, "retire") == 0 )
        {
            string name;
            cin >> name;
            assert( name.size() <= 10 );
            remove_player(name);
        }
        else if( strcmp(ins, "standings") == 0 )
        {
            show_standings();
        }
        else if( strcmp(ins, "profile") == 0 )
        {
            string name;
            cin >> name;
            assert( name.size() <= 10 );
            show_profile(name);
        }
        else if( strcmp(ins, "h2h") == 0 )
        {
            string name1, name2;
            cin >> name1 >> name2;
            assert( name1.size() <= 10 );
            assert( name2.size() <= 10 );
            show_head_to_head(name1, name2);
        }
        else if( strcmp(ins, "play") == 0 )
        {
            string name;
            int k, set_count, rnk;
            cin >> name >> k >> set_count >> rnk;
            assert( name.size() <= 10 );
            assert( 1 <= k && k <= 7 );
            assert( set_count == 1 || set_count == 3 || set_count == 5 );
            play_tournament(name, k, set_count, rnk);
        }
        else assert(false);
        for(int i = 0; i < 30; i++) printf("*");
        puts("");
    }
    return 0;
}