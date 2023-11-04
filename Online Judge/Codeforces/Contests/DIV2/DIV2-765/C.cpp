#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> d(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    d[n] = l;
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        vector<vector<long long>> ndp(n + 1, vector<long long>(k + 1, INF));
        for (int j = 0; j < i; j++) {
            for (int x = 0; x <= k; x++) {
                ndp[i][x] = min(ndp[i][x], dp[j][x] + 1LL * (d[i] - d[i - 1]) * a[j]);
                if (x - 1 >= 0) {
                    ndp[j][x] = min(ndp[j][x], dp[j][x - 1] + 1LL * (d[i] - d[i - 1]) * a[j]);
                }
            }
        }
        dp.swap(ndp);
    }
    long long ans = INF;
    for (int j = 0; j <= n; j++) {
        for (int x = 0; x <= k; x++) {
            ans = min(ans, dp[j][x]);
        }
    }
    cout << ans << '\n';
    
    return 0;
}