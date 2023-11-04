#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i + 1 < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cin >> d[i][j];
            d[j][i] = d[i][j];
        }
    }
    int target = (n & 1 ? n - 1 : n);
    long long ans = 0;
    vector<long long> dp(1 << n);
    for (int mask = 1; mask < (1 << n); mask++) {
        vector<int> on;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                on.emplace_back(i);
            }
        }
        int len = (int) on.size();
        if (len & 1) {
            continue;
        }
        for (int j = 0; j + 1 < len; j++) {
            for (int k = j + 1; k < len; k++) {
                int cmask = mask - (1 << on[j]) - (1 << on[k]);
                dp[mask] = max(dp[mask], dp[cmask] + d[on[j]][on[k]]);
            }
        }
        if (len == target) {
            ans = max(ans, dp[mask]);
        }
    }
    cout << ans << '\n';
    
    return 0;
}