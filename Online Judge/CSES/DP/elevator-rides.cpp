#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    vector<pair<int, int>> dp(1 << n);
    dp[0] = {1, 0};
    for (int mask = 1; mask < (1 << n); mask++) {
        dp[mask] = {n + 1, 0};
        for (int i = 0; i < n; i++) {
            bool bit = mask & (1 << i);
            if (!bit) {
                continue;
            }
            int bmask = (mask ^ (1 << i));
            auto [rides, sum] = dp[bmask];
            if (sum + w[i] <= x) {
                sum += w[i];
            } else {
                rides++;
                sum = w[i];
            }
            dp[mask] = min(dp[mask], {rides, sum});
        }
    }
    cout << dp[(1 << n) - 1].first << '\n';
    
    return 0;
}