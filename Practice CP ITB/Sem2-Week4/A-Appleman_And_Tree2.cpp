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

// source : http://codeforces.com/contest/462/submission/7677996

const int N = 1e5+5;
int n;
vector<ll> g[N]; int c[N];
ll dp[N][2];

void dfs(int v, int p){
    if(c[v] == 1){
        dp[v][0] = 0;
        dp[v][1] = 1;
    }else{
        dp[v][0] = 1;
        dp[v][1] = 0;
    }

    for(auto u:g[v]){
        if(u == p)continue;
        dfs(u,v);
        if(c[v] == 1){
            dp[v][1] *= (dp[u][0] + dp[u][1]) %MOD; dp[v][1] %= MOD;
        }else{
            // Assume that dp[v][1] stores the num solutions if there
			// is a single black node in the children from 1-(u-1).

			// First suppose the black node does not come from u.
			// Then it must be between 1-(u-1).
			// So multiply dp[v][1], which stores that, by dp[u][0],
			// which is the number of ways to arrange arrange the whites in u.

			// Now suppose that the black node does come from u.
			// How many ways are there to get the black node? This is just dp[u][1] but we must also
			// multiply it by the number of ways to ensure all children from 1 - (u-1) are white.
			// This value is stored for us in dp[v][0].
            dp[v][1] *= (dp[u][0] + dp[u][1]) % MOD;
			dp[v][1] = dp[v][1] % MOD;
			dp[v][1] += (dp[v][0] * dp[u][1]) % MOD;
			dp[v][1] = dp[v][1] % MOD;

			// Assume that dp[v][0] stores the num solutions if there is are
			// no black nodes in children from 1-(u-1).
			// Then for the next child, there continue to be no children.
			// If u is connected to v, there are dp[u][0] ways.
			// If u is not connected to v, there are dp[u][1] ways.
			// You add these together (the total number of ways)
			// and multiply by the already-existing combinations.
			dp[v][0] *= (dp[u][0] + dp[u][1]) % MOD;
			dp[v][0] = dp[v][0] % MOD;
        }
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
    cout << (dp[0][1]%MOD+MOD)%MOD << "\n";

    return 0;
}
