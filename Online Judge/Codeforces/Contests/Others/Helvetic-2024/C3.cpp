#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, t;
    cin >> n >> t;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int> nodes(t);
    for (int i = 0; i < t; i++) {
        cin >> nodes[i];
    }
    vector<bool> dp(n + 1);
    vector<bool> ans(n + 1);

    function<void(int, int)> dfs = [&](int u, int p) {
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            if (!dp[v]) {
                dp[u] = true;
            }
        }
    };

    function<void(int, int)> reroot = [&](int u, int p) {
        ans[u] = dp[u];
        int at = -1;
        int cnt = 0;
        for (int v : adj[u]) {
            if (!dp[v]) {
                at = v;
                ++cnt;
            }
        }
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            bool dpu = dp[u];
            bool dpv = dp[v];
            if (dp[u] && cnt == 1 && at == v) {
                dp[u] = false;
            }
            if (!dp[v] && !dp[u]) {
                dp[v] = true;
            }
            reroot(v, u);
            dp[u] = dpu;
            dp[v] = dpv;
        }
    };

    dfs(1, 1);
    reroot(1, 1);

    for (int u : nodes) {
        cout << (ans[u] ? "Ron" : "Hermione") << '\n';
    }
    
    return 0;
}