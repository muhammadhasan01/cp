#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    bool possible = true;
    vector<int> col(n + 1, -1);

    function<void(int)> dfs = [&](int u) {
        for (int v : adj[u]) {
            if (col[v] == -1) {
                col[v] = (col[u] == 1 ? 0 : 1);
                dfs(v);
            } else if (col[v] == col[u]) {
                possible = false;
                return;
            }
        }
    };

    for (int u = 1; u <= n; u++) {
        if (col[u] == -1) {
            col[u] = 1;
            dfs(u);
            if (!possible) {
                cout << "NO" << '\n';
                return 0;
            }
        }
    }
    cout << "YES" << '\n';
    for (auto [u, v] : edges) {
        cout << col[v];
    }
    cout << '\n';
    
    return 0;
}