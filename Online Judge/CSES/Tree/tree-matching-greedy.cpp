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
    int ans = 0;
    vector<bool> taken(n + 1);

    function<void(int, int)> dfs = [&](int u, int p) {
        bool leaf = true;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            if (!taken[v]) {
                leaf = false;
            }
        }
        if (!leaf || taken[u] || taken[p] || u == p) {
            return;
        }
        taken[u] = true;
        taken[p] = true;
        ans++;
    };

    dfs(1, 1);
    cout << ans << '\n';
    
    return 0;
}