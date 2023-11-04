#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].emplace_back(v, i);
    }

    vector<int> dist(n, -1), parEdge(n, -1), parNode(n, -1);

    auto BFS = [&](int avoid = -1) -> void {
        fill(dist.begin(), dist.end(), -1);
        queue<int> q;
        dist[0] = 0;
        q.emplace(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto [v, i] : adj[u]) {
                if (i == avoid) {
                    continue;
                }
                if (dist[v] == -1) {
                    if (avoid == -1) {
                        parNode[v] = u;
                        parEdge[v] = i;
                    }
                    dist[v] = 1 + dist[u];
                    q.emplace(v);
                }
            }
        }
    };

    BFS();
    if (dist[n - 1] == -1) {
        for (int u = 0; u < m; u++) {
            cout << -1 << '\n';
        }
        return 0;
    }
    vector<int> ans(m, dist[n - 1]);
    for (int u = n - 1; u != 0; u = parNode[u]) {
        int i = parEdge[u];
        BFS(i);
        ans[i] = dist[n - 1];
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}