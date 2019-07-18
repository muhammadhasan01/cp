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
#define reset(a,b) memset(a,(b),sizeof(a))
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 3e5+5;
int n, vis[N];
ll ans = 0, w[N];
vector<pair<ll,int> > g[N];

ll dfs(int v){
    vis[v] = 1;
    ll res = w[v];
    for(auto e:g[v]){
        int k = e.ff;
        ll c = e.ss;
        if(!vis[k]){
            ll sum = dfs(k);
            sum -= c;
            ans = max(ans, res+sum);
            res = max(res, w[v]+sum);
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n)cin>>w[i], ans = max(ans,w[i]);
    forn(i,1,n-1){
        int u,v; ll c;
        cin >> u >> v >> c;
        g[u].pb({v,c});
        g[v].pb({u,c});
    }

    dfs(1);
    cout << ans << "\n";

    return 0;
}
