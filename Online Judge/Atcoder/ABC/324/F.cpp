#include <bits/stdc++.h>

using namespace std;

const long double INF = 1e9 + 5;
const int REP = 100;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<long long> b(m + 1), c(m + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v >> b[i] >> c[i];
        adj[u].emplace_back(v, i);
    }
    vector<long double> dp(n + 1);

    auto can = [&](long double x) -> bool {
        fill(dp.begin(), dp.end(), -INF);
        dp[1] = 0;
        for (int u = 1; u <= n; u++) {
            for (auto& [v, i] : adj[u]) {
                dp[v] = max(dp[v], dp[u] + b[i] - c[i] * x);
            }
        }
        return dp[n] >= 0;
    };

    long double l = 0, r = INF;
    for (int rep = 0; rep < REP; rep++) {
        long double mid = (l + r) / 2.0;
        if (can(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(12) << l << '\n';
    
    return 0;
}