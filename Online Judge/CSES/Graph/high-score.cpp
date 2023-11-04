#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1), radj(n + 1);
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        adj[u].emplace_back(v);
        radj[v].emplace_back(u);
        edges.emplace_back(u, v, -x);
    }

    auto getVis = [&](vector<vector<int>>& a, int s) -> vector<bool> {
        vector<bool> vis(n + 1);
        queue<int> q;
        vis[s] = true;
        q.emplace(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : a[u]) {
                if (vis[v]) {
                    continue;
                }
                vis[v] = true;
                q.emplace(v);
            }
        }
        return vis;
    };

    vector<bool> vis = getVis(adj, 1);
    vector<bool> rvis = getVis(radj, n);
    vector<long long> dist(n + 1, INF);
    dist[1] = 0;
    for (int rep = 1; rep <= n; rep++) {
        for (auto [u, v, w] : edges) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (rep == n && vis[v] && rvis[v]) {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }
    cout << -dist[n] << '\n';
    
    return 0;
}