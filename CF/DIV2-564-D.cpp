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

const int M = 998244353;
const int N = 2e5+5;
int n;
vector<int> g[N];
ll pre[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n-1){
        int u,v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }

    pre[0] = 1;
    forn(i,1,n-1){
        pre[i] = (i * pre[i-1])%M;
    }

    ll ans = n;
    forn(i,1,n){
        ans *= (pre[len(g[i])] % M);
        ans %= M;
    }

    cout << (ans%M + M)%M << "\n";


    return 0;
}
