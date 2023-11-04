#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<char> s(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> dp(2);
    for (int i = n; i >= 1; i--) {
        vector<int> ndp(2);
        if (s[i] == '1') {
            ndp[0] = a[i] + dp[0];
            if (i - 1 >= 1) {
                ndp[1] = dp[0];
            }
            if (i + 1 <= n && s[i + 1] == '1') {
                ndp[0] = max(ndp[0], a[i] + dp[1]);
                if (i - 1 >= 1) {
                    ndp[1] = max(ndp[1], a[i] + dp[1]);
                }
            }
        } else if (s[i] == '0') {
            ndp[0] = dp[0];
            if (i + 1 <= n && s[i + 1] == '1') {
                ndp[0] = max(ndp[0], a[i] + dp[1]);
            }
        }
        ndp.swap(dp);
    }
    cout << max({dp[0], dp[1]}) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}