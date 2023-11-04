#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<vector<int>> dp(n, vector<int>(m + 1));
    if (x[0] == 0) {
        for (int j = 1; j <= m; j++) {
            dp[0][j] = 1;
        }
    } else {
        dp[0][x[0]] = 1;
    }
    for (int i = 1; i < n; i++) {
        int l = x[i] == 0 ? 1 : x[i];
        int r = x[i] == 0 ? m : x[i];
        for (int j = l; j <= r; j++) {
            for (int jb : {j - 1, j, j + 1}) {
                if (jb < 0 || jb > m) {
                    continue;
                }
                dp[i][j] = (dp[i][j] + dp[i - 1][jb]) % MOD;
            }
        }
    }
    int ans = 0;
    for (int j = 1; j <= m; j++) {
        ans = (ans + dp[n - 1][j]) % MOD;
    }
    cout << ans << '\n';
    
    return 0;
}