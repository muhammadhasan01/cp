#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end(), [&](auto& lhs, auto& rhs) {
        return lhs + rhs < rhs + lhs;
    });
    reverse(s.begin(), s.end());
    vector<string> dp = s;
    for (int j = 2; j <= k; j++) {
        vector<string> ndp(n);
        for (int i = j - 1; i < n; i++) {
            for (int x = j - 2; x < i; x++) {
                if (ndp[i].empty()) {
                    ndp[i] = s[i] + dp[x];
                } else {
                    ndp[i] = min(ndp[i], s[i] + dp[x]);
                }
            }
        }
        dp.swap(ndp);
    }
    string ans = "";
    for (int i = k - 1; i < n; i++) {
        if (ans.empty()) {
            ans = dp[i];
        } else {
            ans = min(ans, dp[i]);
        }
    }
    cout << ans << '\n';

    return 0;
}