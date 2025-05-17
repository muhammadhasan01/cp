#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector dp(n, vector(m, -INF));
    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }
    dp[0][1 % m] = max(dp[0][1 % m], a[0] - k);
    for (int i = 1; i < n; i++) {
        long long sum = 0;
        for (int j = i, len = 1; j > 0 && len <= 1; j--, len++) {
            sum += a[j];
            for (int x = 0; x < m; x++) {
                int nx = (x + len) % m;
                long long add = 0;
                if (x == 0 || x + len > m) {
                    add -= k;
                }
                dp[i][nx] = max(dp[i][nx], dp[j - 1][x] + sum + add);
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
    
    return 0;
}