#include <bits/stdc++.h>

using namespace std;

const long long INF = 4e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    int m = n * n;
    vector<long long> dp(m + 1, INF);
    for (int i = 1; i <= n; i++) {
        cin >> dp[i];
    }
    vector<long long> ndp(n + 1);
    for (int i = 1; i <= n; i++) {
        ndp[i] = dp[i];
        for (int j = 1; j < i; j++) {
            ndp[i] = min(ndp[i], ndp[j] + ndp[i - j]);
        }
    }
    for (int i = n + 1; i <= m; i++) {
        for (int j = 1; j < i; j++) {
            int k = i - j;
            if (j > k) {
                break;
            }
            if (j <= n && k > n) {
                dp[i] = min(dp[i], ndp[j] + dp[k]);
            }
            dp[i] = min(dp[i], dp[j] + dp[k]);
        }
    }
    long long val = ndp[n];
    int idx = n;
    while (q--) {
        int k;
        cin >> k;
        if (k <= m) {
            cout << dp[k] << '\n';
        } else {
            long long res = INF;
            for (int i = 1; i <= n; i++) {
                long long val = ndp[i];
                int idx = i;
                long long dif = (k - m + idx - 1) / idx;
                long long ans = val * dif;
                k = k - dif * idx;
                ans += dp[k];
                res = min(res, ans);
            }
            cout << res << '\n';
        }
    }
    
    return 0;
}