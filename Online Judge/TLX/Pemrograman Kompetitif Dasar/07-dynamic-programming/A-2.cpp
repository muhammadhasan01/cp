#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int K = 5e4 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(K, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < K; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            if (j - x >= 0 && dp[i][j - x] != INF) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - x]);
            }
        }
    }
    int k;
    cin >> k;
    cout << dp[n][k] << '\n';
    
    return 0;
}