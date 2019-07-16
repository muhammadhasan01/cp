#include<bits/stdc++.h>
using namespace std;

const int M = 1e8;
const int N = 105;
int n1,n2,k1,k2;
long long dp[N][N][3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n1 >> n2 >> k1 >> k2;
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            for(int k=1;k<=min(n1-i,k1);k++){
                dp[i+k][j][0] += dp[i][j][1];
                dp[i+k][j][0] %= M;
            }
            for(int k=1;k<=min(n2-j,k2);k++){
                dp[i][j+k][1] += dp[i][j][0];
                dp[i][j+k][1] %= M;
            }
        }
    }
    cout << ((dp[n1][n2][0]%M + dp[n1][n2][1]%M) + M)%M << "\n";

    return 0;
}
