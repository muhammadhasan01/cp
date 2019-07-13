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

// https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/
// https://vjudge.net/problem/HihoCoder-1338

// Consider a row of n coins of values v1 . . . vn, where n is even.
// We play a game against an opponent by alternating turns.
// In each turn, a player selects either the first or last coin from the row,
// removes it from the row permanently, and receives the value of the coin.
// Determine the maximum possible amount of money we can definitely win if we move first.

const int NMAX = 1000;
ll a[NMAX+3], ans = 0;
int n;

// Optimal Substructure :
// dp[i][j] = a[i] (if i == j)
// dp[i][j] = max(a[i],a[j]) (if i+1 == j)
// dp[i][j] = max(a[i]+min(dp[i+2][j], dp[i+1][j-1]), a[j]+min(dp[i][j-2],dp[i+1][j-1]))

ll optimal_strategy(){

    if(n == 1){
        return a[n];
    }

    ll dp[n+3][n+3];

    for(int j=0;j<=n-1;j++){
        for(int i=1;i+j<=n;i++){
            if(j == 0){
                dp[i][i+j] = a[i];
            }else if(j == 1){
                dp[i][i+j] = max(a[i],a[i+j]);
            }else{
                int k = i+j;
                dp[i][k] = max(a[i]+min(dp[i+2][k],dp[i+1][k-1]),a[k]+min(dp[i][k-2],dp[i+1][k-1]));
            }
        }
    }

    return dp[1][n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    cout << optimal_strategy() << "\n";
    return 0;
}
