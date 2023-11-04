#include <bits/stdc++.h>

using namespace std;
using pll = pair<long long, long long>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<vector<pll>> dp(n, vector<pll>(n));
    for (int len = 1; len <= n; len++) {
        for (int l = 0; l < n; l++) {
            int r = l + len - 1;
            if (r >= n) {
                break;
            }
            if (l == r) {
                dp[l][r] = make_pair(x[l], 0LL);
            } else {
                pll L = make_pair(x[l] + dp[l + 1][r].second, dp[l + 1][r].first);
                pll R = make_pair(x[r] + dp[l][r - 1].second, dp[l][r - 1].first);
                if (L.first > R.first) {
                    dp[l][r] = L;
                } else if (L.first == R.first) {
                    dp[l][r] = (L.second < R.second ? L : R);
                } else {
                    dp[l][r] = R;
                }
            }
        }
    }
    cout << dp[0][n - 1].first << '\n';

    return 0;
}