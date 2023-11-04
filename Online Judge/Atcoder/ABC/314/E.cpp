#include <bits/stdc++.h>

using namespace std;

const double INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    vector<vector<int>> val(n);
    vector<int> sz(n);
    vector<int> zeroes(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        cin >> sz[i];
        for (int j = 0; j < sz[i]; j++) {
            int x;
            cin >> x;
            if (x > 0) {
                val[i].emplace_back(x);
            } else {
                zeroes[i]++;
            }
        }
    }
    vector<double> dp(m + 1, INF);
    dp[0] = 0.0;
    for (int cost = 1; cost <= m; cost++) {
        for (int i = 0; i < n; i++) {
            double cur = c[i];
            int len = (int) val[i].size();
            for (int x : val[i]) {
                cur += dp[max(0, cost - x)] / sz[i]; 
            }
            cur *= (double) sz[i] / (sz[i] - zeroes[i]);
            dp[cost] = min(dp[cost], cur);
        }
    }
    cout << fixed << setprecision(12) << dp[m] << '\n';
    
    return 0;
}