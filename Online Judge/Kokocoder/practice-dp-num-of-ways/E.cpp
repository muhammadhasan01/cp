#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e8;
const int N1 = 205;
const int N2 = 205;
const int K = 2;

int dp[N1][N2][K];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            if (i == 0 && j == 0) {
                dp[i][j][0] = dp[i][j][1] = 1;
                continue;
            }
            for (int take = 1; take <= min(i, k1); take++) {
                dp[i][j][0] += dp[i - take][j][1] % MOD;
            }
            for (int take = 1; take <= min(j, k2); take++) {
                dp[i][j][1] += dp[i][j - take][0] % MOD;
            }
        }
    }
    int ans = (dp[n1][n2][0] + dp[n1][n2][1]) % MOD;
    cout << ans << '\n';
    
    return 0;
}