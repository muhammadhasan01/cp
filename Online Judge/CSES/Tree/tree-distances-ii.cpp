#include <bits/stdc++.h>

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<long long> ans(n + 1);
    vector<long long> dp(n + 1);
    vector<int> sz(n + 1);

    function<void(int, int)> dfs = [&](int u, int p) {
        sz[u] = 1;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            sz[u] += sz[v];
            dp[u] += dp[v] + sz[v];
        }
    };

    function<void(int, int)> reroot = [&](int u, int p) {
        if (u == p) {
            ans[u] = dp[u];
        } else {
            ans[u] = ans[p] - sz[u] + (n - sz[u]);
        }
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            reroot(v, u);
        }
    };

    dfs(1, 1);
    reroot(1, 1);

    for (int u = 1; u <= n; u++) {
        cout << ans[u] << " \n"[u == n];
    }
    
    return 0;
}