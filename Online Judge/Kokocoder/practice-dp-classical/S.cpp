#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> mask_len(n + 1);
    for (int mask = 0; mask < (1 << n); mask++) {
        int len = __builtin_popcount(mask);
        mask_len[len].emplace_back(mask);
    }
    vector<int> dp(1 << n);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        vector<int> ndp(1 << n);
        for (int mask : mask_len[i]) {
            for (int j = 0; j < n; j++) {
                if (a[i][j + 1] == 0) {
                    continue;
                }
                bool bit = (mask & (1 << j));
                if (!bit) {
                    continue;
                }
                int bmask = (mask ^ (1 << j));
                ndp[mask] = (ndp[mask] + dp[bmask]) % MOD;
            }
        }
        ndp.swap(dp);
    }
    cout << dp[(1 << n) - 1] << '\n';

    return 0;
}