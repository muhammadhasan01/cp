#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(2 * n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[u].emplace_back(v + n, w / 2);
        adj[u + n].emplace_back(v + n, w);
    }
    vector<long long> dist(2 * n + 1, INF);
    dist[1] = 0;
    priority_queue<pair<long long, int>> pq;
    pq.emplace(-dist[1], 1);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] != -d) {
            continue;
        }
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(-dist[v], v);
            }
        }
    }
    cout << min(dist[n], dist[n + n]) << '\n';
    
    return 0;
}