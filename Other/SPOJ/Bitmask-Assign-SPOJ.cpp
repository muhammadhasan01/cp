#include<bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/ASSIGN/
// solution : https://github.com/fazlulkabir94/spoj-problem-solution/blob/master/ASSIGN%20-%20Assignments.cpp

int tc,n;
int p[25][25];
long long dp[(1<<20)+5];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while(tc--){
        cin >> n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> p[i][j];
            }
        }
        fill(dp,dp+(1<<n)+1,0);
        dp[0] = 1;
        int maxi = (1<<n);
        for(int mask=0;mask<maxi;mask++){
            int k = __builtin_popcount(mask);
            for(int i=0;i<n;i++){
                if((p[k][i] == 1) && (mask & (1<<i)) == 0){
                    dp[mask|(1<<i)] += dp[mask];
                }
            }
        }
        cout << dp[maxi-1] << '\n';
    }



    return 0;
}
