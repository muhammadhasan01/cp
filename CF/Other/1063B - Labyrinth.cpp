#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf int_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define forn(i,n) for(int i=0;i<int(n);i++)
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 2000;
ll n,m,r,c,x,y;
char a[N+2][N+2];
int vis[N+2][N+2];

ll bfs(ll r, ll c){
    vis[r][c] = 1;
    queue<pair<ll,ll> > q;
    queue<pair<ll,ll> > loc;
    q.push(mp(x,y));
    loc.push(mp(r,c));
    char chr; ll x1,y1, R, C, loc1, loc2;
    ll ans = 1;
    int rw[2] = {1,-1}, cl[2] = {0,0};
    while(!q.empty()){
        x1 = q.front().ff, y1 = q.front().ss;
        loc1 = loc.front().ff; loc2 = loc.front().ss;
        cout << "(" << a[loc1][loc2] << "," << loc1+1 << "," << loc2+1 << ") => (" << x1 << "," << y1 << ")\n";
        q.pop(); loc.pop();
        for(int i=0; i<2;i++){
            R = loc1+rw[i];
            C = loc2+cl[i];
            if(0 <= R && R < n && 0 <= C && C < m && vis[R][C] == 0){
                vis[R][C] = 1;
                if(a[R][C] == '.'){
                    ans++;
                    q.push(mp(x1,y1));
                    loc.push(mp(R,C));
                }
            }
        }
        R = loc1;
        C = loc2+1;
        if(0 <= C && C < m && vis[R][C] == 0 && 0 < y1){
            vis[R][C] = 1;
            if(a[R][C] == '.'){
                ans++;
                q.push(mp(x1,y1-1));
                loc.push(mp(R,C));
            }
        }
        R = loc1;
        C = loc2-1;
        if(0 <= C && C < m && vis[R][C] == 0 && 0 < x1){
            vis[R][C] = 1;
            if(a[R][C] == '.'){
                ans++;
                q.push(mp(x1-1,y1));
                loc.push(mp(R,C));
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r >> c >> x >> y;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    MEM(vis,0);
    cout << bfs(r-1,c-1) << "\n";
    return 0;
}
