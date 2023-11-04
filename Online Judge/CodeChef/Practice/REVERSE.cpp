#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> radj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        radj[v].emplace_back(u);
    }
    vector<int> dist(n + 1, -1);
    dist[1] = 0;
    deque<pair<int, int>> dq;
    dq.emplace_front(1, dist[1]);
    while (!dq.empty()) {
        auto [u, d] = dq.front();
        dq.pop_front();
        if (dist[u] != d) {
            continue;
        }
        for (int v : adj[u]) {
            if (dist[v] == -1 || dist[v] > dist[u]) {
                dist[v] = dist[u];
                dq.emplace_front(v, dist[v]);
            }
        }
        for (int v : radj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                dq.emplace_back(v, dist[v]);
            }
        }
    }
    cout << dist[n] << '\n';
    
    return 0;
}