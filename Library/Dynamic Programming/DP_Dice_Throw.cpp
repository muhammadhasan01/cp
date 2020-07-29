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
#define debug1(i) printf("debug => %ld\n",i);
#define debug2(i,j) printf("debug => %ld - %ld\n",i,j);
#define debug3(i,j,k) printf("debug => %ld - %ld - %ld\n",i,j,k);
#define MEM(a,b) memset(a,(b),sizeof(a))
#define sizearr(arr) sizeof(arr)/sizeof(arr[0])
#define LEN(x) (int)x.size()
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// Given n dice each with m faces, numbered from 1 to m, find the number of ways to get sum X
// https://www.geeksforgeeks.org/dice-throw-dp-30/
// https://practice.geeksforgeeks.org/problems/dice-throw/0

int tc, m,n,x;

// Optimal Substructure :
// dp[i][j] = number of ways to have a value j with i cubes
// dp[i][0] = 0 (if j < i)
// dp[i][j] = 1 (if i == j)
// dp[i][j] = 1 (if i == 1 and 1 <= j <= m) else 0
// dp[i][j] = sum(dp[i][j-k]) where 1 <= k <= j

ll dice_throw(){
    ll dp[n+3][x+3];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(j == 0){
                dp[i][j] = 0;
            }else if(i == 1){
                if(1 <= j  && j <= m){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = 0;
                }
            }else{
                if(j < i){
                    dp[i][j] = 0;
                }else if(i == j){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = 0;
                    for(int k=1;k<=min(m,j);k++){
                        dp[i][j] += dp[i-1][j-k];
                    }
                }
            }
        }
    }
    return dp[n][x];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--){
        cin >> m >> n >> x;
        cout << dice_throw() << "\n";
    }

    return 0;
}
