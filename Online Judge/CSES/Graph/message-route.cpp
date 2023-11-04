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
    vector<int> par(n + 1, -1);
    vector<int> dist(n + 1, -1);
    queue<int> q;
    int source = 1;
    q.emplace(source);
    dist[source] = 0;
    par[source] = source;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = 1 + dist[u];
                par[v] = u;
                q.emplace(v);
            }
        }
    }
    if (dist[n] == -1) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    cout << dist[n] + 1 << '\n';
    vector<int> path;
    for (int u = n; u != 1; u = par[u]) {
        path.emplace_back(u);
    }
    path.emplace_back(1);
    reverse(path.begin(), path.end());
    int len = path.size();
    for (int i = 0; i < len; i++) {
        cout << path[i] << " \n"[i == len - 1];
    }

    return 0;
}