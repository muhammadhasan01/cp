#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<tuple<int, int, int>> projects(n);
    for (auto& [b, a, p] : projects) {
        cin >> a >> b >> p;
    }
    sort(projects.begin(), projects.end());
    vector<long long> dp(n);
    for (int i = 0; i < n; i++) {
        auto [b, a, p] = projects[i];
        dp[i] = p;
        if (i > 0) {
            dp[i] = max(dp[i], dp[i - 1]);
        }
        int l = 0, r = i - 1, at = - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (get<0>(projects[mid]) < a) {
                at = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (at != -1) {
            dp[i] = max(dp[i], p + dp[at]);
        }
    }
    cout << dp[n - 1] << '\n';
    
    return 0;
}