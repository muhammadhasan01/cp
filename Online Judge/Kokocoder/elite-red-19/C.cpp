#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int> dp(n + 1);
    for (int u = 1; u <= n; u++) {
        dp[u] = 1;
        for (int v : adj[u]) {
            if (v < u) {
                dp[u] = max(dp[u], 1 + dp[v]);
            }
        }
    }
    long long ans = 0;
    for (int u = 1; u <= n; u++) {
        long long cur = 1LL * dp[u] * ((int) adj[u].size());
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}