#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<tuple<int, int, int>> v(n);
    for (int i = 0; i < n; i++) {
        auto& [b, a, p] = v[i];
        cin >> a >> b >> p;
    }
    sort(v.begin(), v.end());
    vector<long long> dp(n);
    for (int i = 0; i < n; i++) {
        auto [b, a, p] = v[i];
        int l = 0, r = i - 1, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (get<0>(v[mid]) < a) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        if (i > 0) {
            dp[i] = max(dp[i], dp[i - 1]);
        }
        dp[i] = max(dp[i], (at != -1 ? dp[at] : 0LL) + p);
    }
    cout << dp[n - 1] << '\n';
    
    return 0;
}