#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].emplace_back(v, w);
    }
    int all = (1 << n) - 1;
    vector<vector<int>> dist(n, vector<int>(all + 1, INF));
    priority_queue<tuple<int, int, int>> pq;
    for (int u = 0; u < n; u++) {
        int mask = (1 << u);
        dist[u][mask] = 0;
        pq.emplace(-dist[u][mask], u, mask);
    }
    while (!pq.empty()) {
        auto [d, u, mask] = pq.top();
        pq.pop();
        if (dist[u][mask] != -d) {
            continue;
        }
        for (auto [v, w] : adj[u]) {
            int cmask = mask | (1 << v);
            if (dist[v][cmask] > dist[u][mask] + w) {
                dist[v][cmask] = dist[u][mask] + w;
                pq.emplace(-dist[v][cmask], v, cmask);
            }
        }
    }
    int ans = INF;
    for (int u = 0; u < n; u++) {
        ans = min(ans, dist[u][all]);
    }
    if (ans == INF) {
        cout << "No" << '\n';
        return 0;
    }
    cout << ans << '\n';
    
    return 0;
}