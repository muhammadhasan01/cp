#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    getline(cin, s);
    int n, p, q;
    cin >> n >> p >> q;
    vector<tuple<int, int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int b, d, w;
        cin >> b >> d >> w;
        a[i] = make_tuple(w, b, d);
    }
    sort(a.begin(), a.end());
    vector<vector<vector<int>>> dp(p + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
    {
        dp[0][0][0] = 0;
        auto [w, b, d] = a[0];
        if (b <= p) {
            dp[b][1][1] = d;
        }
    }
    for (int i = 1; i < n; i++) {
        vector<vector<vector<int>>> ndp(p + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        auto [wi, bi, di] = a[i];
        auto [wj, bj, dj] = a[i - 1];
        for (int cb = 0; cb <= p; cb++) {
            for (int cq = 0; cq <= n; cq++) {
                if (wi == wj) {
                    ndp[cb][cq][1] = dp[cb][cq][1];
                    ndp[cb][cq][0] = dp[cb][cq][0];
                    if (cb - bi >= 0) {
                        if (dp[cb - bi][cq][1] != -1) {
                            ndp[cb][cq][1] = max(ndp[cb][cq][1], di + dp[cb - bi][cq][1]);
                        }
                        if (cq - 1 >= 0 && dp[cb - bi][cq - 1][0] != -1) {
                            ndp[cb][cq][1] = max(ndp[cb][cq][1], di + dp[cb - bi][cq - 1][0]);
                        }
                    }
                } else {
                    ndp[cb][cq][0] = max(dp[cb][cq][0], dp[cb][cq][1]);
                    if (cq - 1 >= 0 && cb - bi >= 0) {
                        int cur = max(dp[cb - bi][cq - 1][0], dp[cb - bi][cq - 1][1]);
                        if (cur != -1) {
                            ndp[cb][cq][1] = max(ndp[cb][cq][1], di + cur);
                        }
                    }
                }
            }
        }
        dp.swap(ndp);
    }
    int ans = -1;
    for (int cb = 0; cb <= p; cb++) {
        for (int cq = q; cq <= n; cq++) {
            ans = max(ans, dp[cb][cq][0]);
            ans = max(ans, dp[cb][cq][1]);
        }
    }
    cout << ans << '\n';
    
    return 0;
}