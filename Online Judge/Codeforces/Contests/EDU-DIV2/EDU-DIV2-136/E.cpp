#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int K = 2;

void solve() {
    int n;
    cin >> n;
    vector<string> a(K);
    for (int i = 0; i < K; i++) {
        cin >> a[i];
    }
    vector<array<array<int, K>, K>> dp(n);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < K; i++) {
            for (int k = 0; k < K; k++) {
                dp[j][i][k] = -INF;
            }
        }
    }
    dp[0][0][0] = 0;
    dp[0][0][a[1][0] == '1'] = a[1][0] == '1';
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < K; i++) {
            int x = a[i][j] == '1';
            int y = a[(i ^ 1)][j] == '1';
            dp[j][i][0] = max(dp[j][i][0], dp[j - 1][i][0] + x);
            dp[j][i][0] = max(dp[j][i][0], dp[j - 1][(i ^ 1)][1] + x);
            dp[j][i][y] = max(dp[j][i][y], dp[j - 1][i][0] + x + y);
        }
    }
    int ans = -INF;
    for (int i = 0; i < K; i++) {
        for (int k = 0; k < K; k++) {
            ans = max(ans, dp[n - 1][i][k]);
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}