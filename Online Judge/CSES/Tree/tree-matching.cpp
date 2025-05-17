#include <bits/stdc++.h>

using namespace std;

int main() {
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
    vector<vector<int>> dp(n + 1, vector<int>(2));

    function<void(int, int)> dfs = [&](int u, int p) {
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
        }
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dp[u][1] = max(dp[u][1], dp[u][0] - max(dp[v][0], dp[v][1]) + dp[v][0] + 1);
        }
    };

    dfs(1, 1);
    cout << max(dp[1][0], dp[1][1]) << '\n';
    
    return 0;
}