#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define forn(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define nrof(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define LEN(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 1e5+3;
const int M = 303;

int n,m;
int a[N], t[4*N], lazy[4*N], ans = -inf, pos = 0;
vector<int> b[N], Plus[N], Minus[N];
pii q[M];

void build(int v, int s, int e){
    if(s == e){
        t[v] = a[s];
    }else{
        int m = (s+e)/2;
        build(2*v,s,m);
        build(2*v+1,m+1,e);
        t[v] = min(t[2*v], t[2*v+1]);
    }
}

void update(int v, int s, int e, int l, int r, int x){
    if(lazy[v] != 0){
        t[v] += lazy[v];
        if(s != e){
            lazy[2*v] += lazy[v];
            lazy[2*v+1] += lazy[v];
        }
        lazy[v] = 0;
    }

    if(s > r || l > e || s > e){
        return;
    }

    if(l <= s && e <= r){
        t[v] += x;
        if(s != e){
            lazy[2*v] += x;
            lazy[2*v+1] += x;
         }
         return;
    }

    int m = (s+e)/2;
    update(2*v,s,m,l,r,x);
    update(2*v+1,m+1,e,l,r,x);
    t[v] = min(t[2*v],t[2*v+1]);
}

int query(int v, int s, int e, int l, int r){
    if(s > e || s > r || l > e){
        return inf;
    }

    if(lazy[v] != 0){
        t[v] += lazy[v];
        if(s != e){
            lazy[2*v] += lazy[v];
            lazy[2*v+1] += lazy[v];
        }
        lazy[v] = 0;
    }

    if(l <= s && e <= r){
        return t[v];
    }

    int m = (s+e)/2;
    int q1 = query(2*v,s,m,l,r);
    int q2 = query(2*v+1,m+1,e,l,r);
    return min(q1,q2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    forn(i,1,n)cin >> a[i];
    build(1,1,n);
    forn(i,1,m)cin >> q[i].ff >> q[i].ss, update(1,1,n,q[i].ff,q[i].ss,-1);
    forn(j,1,m){
        forn(i,1,n){
            if(i < q[j].ff || i > q[j].ss){
                b[i].pb(j);
            }
        }
        Plus[q[j].ss+1].pb(j);
        Minus[q[j].ff].pb(j);
    }

    forn(i,1,n){
        //cerr << LEN(Plus[i]) << " , " << LEN(Minus[i]) << "\n";
        for(auto e:Plus[i]){
            //cerr << "+" << q[e].ff << "," << q[e].ss << "\n";
            update(1,1,n,q[e].ff,q[e].ss,-1);
        }

        for(auto e:Minus[i]){
            //cerr << "-" << q[e].ff << "," << q[e].ss << "\n";
            update(1,1,n,q[e].ff,q[e].ss,1);
        }

        int minimum = query(1,1,n,1,n);
        //cerr << i << " => " << a[i] << " => " << a[i]-minimum << "\n";
        if(a[i] - minimum > ans){
            ans = a[i]-minimum;
            pos = i;
        }
    }

    //cerr << "*" << pos << "\n";

    cout << ans << "\n";
    cout << LEN(b[pos]) << "\n";
    for(auto e:b[pos]){
        cout << e << " ";
    }

    return 0;
}
