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
    vector<pll> dp;
    for (int len = 1; len <= n; len++) {
        vector<pll> ndp(n - len + 1);
        for (int l = 0; l < n; l++) {
            int r = l + len - 1;
            if (r >= n) {
                break;
            }
            if (l == r) {
                ndp[l] = make_pair(x[l], 0LL);
            } else {
                pll L = make_pair(x[l] + dp[l + 1].second, dp[l + 1].first);
                pll R = make_pair(x[r] + dp[l].second, dp[l].first);
                if (L.first > R.first) {
                    ndp[l] = L;
                } else if (L.first == R.first) {
                    ndp[l] = (L.second < R.second ? L : R);
                } else {
                    ndp[l] = R;
                }
            }
        }
        dp.swap(ndp);
    }
    cout << dp[0].first << '\n';

    return 0;
}