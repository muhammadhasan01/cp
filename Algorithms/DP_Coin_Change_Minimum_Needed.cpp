#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(i,n) for(int i=0;i<(int)n;i++)
#define forn(i,n) for(int i=1;i<=(int)n;i++)
#define formn(i,n) for(int i=0;i<=(int)n;i++)
#define debug1(i) printf("debug => %d\n",i);
#define debug2(i,j) printf("debug => %d - %d\n",i,j);
#define debug3(i,j,k) printf("debug => %d - %d - %d\n",i,j,k);
#define MEM(a,b) memset(a,(b),sizeof(a))
#define sizearr(arr) sizeof(arr)/sizeof(arr[0])
#define LEN(x) (int)x.size()
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int NMAX = 1000*1000;
int tc;
ll c[NMAX+3], v, n;
ll dp[NMAX+3];

// Optimal Substructure :
// dp[i] = the minimum coin needed to have a value i
// dp[0] = 0
// dp[i] = inf (if it is not possible to have a value i)
// dp[i] = min(dp[i], 1+dp[i - c[j-1]]) (if c[j-1] <= i)

ll minimum_coin(){
    dp[0] = 0; // if the value is 0 then include nothing
    for(int i=1;i<=v;i++){
        dp[i] = inf; // set dp[i] to infinite if it is not possible to have a value i
        for(int j=1;j<=n;j++){
            if(c[j-1] <= i){
                dp[i] = min(dp[i], 1+dp[i - c[j-1]]);
            }
        }
    }
    if(dp[v] == inf){
        dp[v] = -1;
    }
    return dp[v];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--){
        cin >> v >> n;
        for(int i=0;i<n;i++){
            cin >> c[i];
        }
        cout << minimum_coin() << "\n";
    }

    return 0;
}
