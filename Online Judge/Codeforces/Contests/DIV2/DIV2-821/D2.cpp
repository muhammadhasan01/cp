#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long x, y;
    cin >> n >> x >> y;
    string a, b;
    cin >> a >> b;
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            pos.emplace_back(i);
        }
    }
    int len = (int) pos.size();
    if (len == 0) {
        cout << 0 << '\n';
        return;
    }
    if (len & 1) {
        cout << -1 << '\n';
        return;
    }
    if (y <= x) {
        if (len > 2) {
            cout << 1LL * (len / 2) * y << '\n';
            return;
        }
        if (pos[0] + 1 == pos[1]) {
            cout << min(x, 2 * y) << '\n';
        } else {
            cout << y << '\n';
        }
        return;
    }
    long long ans = 1LL * (len / 2) * y;
    vector<vector<long long>> dp(len, vector<long long>(len));
    for (int l = 2; l <= len; l += 2) {
        for (int i = 0; i < len; i++) {
            int j = i + l - 1;
            if (j >= len) {
                break;
            }
            if (l == 2) {
                dp[i][j] = min(y, 1LL * (pos[i + 1] - pos[i]) * x);
            } else {
                dp[i][j] = dp[i][i + 1] + dp[i + 2][j];
                dp[i][j] = min(dp[i][j], dp[i][j - 2] + dp[j - 1][j]);
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + y);
            }
            ans = min(ans, dp[i][j] + 1LL * ((len - l) / 2) * y);
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}