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
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ex exit(0);
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 1e5+5;
int n;
vector<int> g[N]; int c[N];
ll dp[N][2];

void dfs(int v, int p){
    dp[v][0] = 1;
    dp[v][1] = 0;
    for(auto u:g[v]){
        if(u == p)continue;
        dfs(u,v);
        dp[v][1] *= dp[u][0]; dp[v][1] %= MOD;
        dp[v][1] += dp[v][0] * dp[u][1]; dp[v][1] %= MOD;
        dp[v][0] *= dp[u][0]; dp[v][0] %= MOD;
    }
    if(c[v] == 1){
        dp[v][1] = dp[v][0]%MOD;
    }else{
        dp[v][0] += dp[v][1]%MOD;
        dp[v][0] %= MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n-1){
        int x;
        cin >> x;
        g[x].pb(i);
        g[i].pb(x);
    }
    forn(i,0,n-1)cin >> c[i];
    dfs(0,-1);
    cout << (dp[0][1]%MOD + MOD)%MOD << "\n";

    return 0;
}
