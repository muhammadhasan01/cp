#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int src;
    cin >> src;
    queue<int> q;
    vector<int> dist(n + 1, -1);
    dist[src] = 0;
    q.emplace(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = 6 + dist[u];
                q.emplace(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i == src) {
            continue;
        }
        cout << dist[i] << ' ';
    }
    cout << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}