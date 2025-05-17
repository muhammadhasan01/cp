#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int> par(n + 1);
    vector<int> tin(n + 1);
    vector<int> tout(n + 1);
    vector<int> dist(n + 1);
    int tim = 0;
    
    function<void(int, int)> dfs = [&](int u, int p) {
        par[u] = p;
        tin[u] = ++tim;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dist[v] = dist[u] + 1;
            dfs(v, u);
        }
        tout[u] = ++tim;
    };

    dfs(1, 1);

    auto isAncestor = [&](int u, int v) -> bool {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    };

    while (m--) {
        int k;
        cin >> k;
        vector<int> nodes(k);
        for (int i = 0; i < k; i++) {
            cin >> nodes[i];
        }
        int deep = 0, mx = -1;
        for (int u : nodes) {
            if (dist[u] > mx) {
                mx = dist[u];
                deep = u;
            }
        }
        bool ok = true;
        for (int u : nodes) {
            if (isAncestor(u, deep) || isAncestor(par[u], deep)) {
                continue;
            }
            ok = false;
            break;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}