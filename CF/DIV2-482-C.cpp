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

const int N = 3e5+5;
ll n;
int x,y;
ll ans = 0;
ll sz[N], sz2[N];
vector<int> g[N];
bitset<N> vis, vis2;


void dfs(int k){
    vis[k] = 1;
    sz[k]++;
    for(auto e:g[k]){
        if(!vis[e]){
            dfs(e);
            sz[k] += sz[e];
        }
    }
}

void dfs2(int k){
    vis2[k] = 1;
    sz2[k]++;
    for(auto e:g[k]){
        if(!vis2[e]){
            dfs2(e);
            sz2[k] += sz2[e];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> y;
    forn(i,1,n-1){
        int u,v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(y);
    dfs2(x);


    ll ans = n * (n - 1);
    ans -= sz[x] * sz2[y];

    cout << ans << "\n";



    return 0;
}
