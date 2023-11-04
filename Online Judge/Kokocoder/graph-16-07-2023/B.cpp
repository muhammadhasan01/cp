#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<bool> vis(n + 1);
    
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (vis[v]) {
                continue;
            }
            dfs(v);
        }
    };

    vector<int> components;
    for (int u = 1; u <= n; u++) {
        if (vis[u]) {
            continue;
        }
        dfs(u);
        components.emplace_back(u);
    }

    int len = (int) components.size();
    cout << len - 1 << '\n';
    for (int i = 1; i < len; i++) {
        cout << components[i - 1] << ' ' << components[i] << '\n';
    }
    
    return 0;
}