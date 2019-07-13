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


const int N = 2e5+5;
int tc;
int n,m,f[N], p;
int vis[N], c[N];

void dfs(int v, int k, vector<int> g[]){
    vis[v] = 1;
    c[v] = k;
    if(k == 1)p++;
    for(auto e:g[v]){
        if(!vis[e]){
            dfs(e,1-k,g);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while(tc--){
        cin >> n >> m;
        vector<int> g[n+5];
        p = 0;
        forn(i,1,n){
            vis[i] = 0;
            c[i] = 0;
        }
        forn(i,1,m){
            int u,v;cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }

        dfs(1,1,g);

        if(p <= n/2){
            cout << p << "\n";
            forn(i,1,n)if(c[i])cout << i << " ";
            cout <<"\n";
        }else{
            cout << n - p << "\n";
            forn(i,1,n)if(!c[i])cout << i << " ";
            cout << "\n";
        }

    }



    return 0;
}
