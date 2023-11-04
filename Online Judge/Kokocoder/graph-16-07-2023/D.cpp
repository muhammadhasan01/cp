#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    bool possible = true;
    vector<int> col(n + 1, -1);

    function<void(int)> dfs = [&](int u) {
        for (int v : adj[u]) {
            if (col[v] == -1) {
                col[v] = (col[u] == 1 ? 2 : 1);
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
            if (possible) {
                continue;
            }
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }
    for (int u = 1; u <= n; u++) {
        cout << col[u] << " \n"[u == n];
    }
    
    return 0;
}