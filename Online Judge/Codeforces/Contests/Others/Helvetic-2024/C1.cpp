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
    int s;
    cin >> s;
    vector<int> dist(n + 1);

    function<void(int, int)> dfs = [&](int u, int p) {
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dist[v] = 1 + dist[u];
            dfs(v, u);
        }
    };

    dfs(s, s);
    for (int u = 1; u <= n; u++) {
        if ((int) adj[u].size() == 1 && dist[u] & 1) {
            cout << "Ron" << '\n';
            return 0;
        }
    }
    cout << "Hermione" << '\n';
    
    return 0;
}