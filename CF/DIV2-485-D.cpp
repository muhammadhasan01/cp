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
#define len(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ex exit(0);
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 1e5+5;
const int K = 1e3+5;
int n,m,k,s;
int a[N], q[N], ans[N][K];
vector<int> g[N];
vector<int> fk[K];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k >> s;
    forn(i,1,n){
        int x; cin >> x;
        fk[x].pb(i);
    }

    forn(i,1,m){
        int u,v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }

    forn(c,1,k){
        vector<int> dist(n+5, inf);
        int top = 1;
        for(auto e : fk[c]){
            dist[e] = 0;
            q[top++] = e;
        }

        forn(i,1,top){
            int v = q[i];
            for(auto u: g[v]){
                if(dist[u] <= dist[v] + 1)continue;
                dist[u] = dist[v] + 1;
                q[top++] = u;
            }
        }

        forn(i,1,n)ans[i][c] = dist[i];

    }

    forn(i,1,n){
        nth_element(ans[i] + 1, ans[i] + 1 + s, ans[i] + 1 + k);
        int res = 0;
        forn(j,1,s)res += ans[i][j];
        cout << res << " ";
    }



    return 0;
}
