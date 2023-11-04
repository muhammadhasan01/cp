#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, l, t, s, e;
    cin >> n >> l >> t >> s >> e;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= l; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<pair<int, int>> p(t);
    for (int i = 0; i < t; i++) {
        cin >> p[i].first >> p[i].second;
    }
    
    auto getDist = [&](int x) -> vector<int> {
        vector<int> dist(n + 1, INF);
        dist[x] = 0;
        queue<int> q;
        q.emplace(x);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] == INF) {
                    dist[v] = 1 + dist[u];
                    q.emplace(v);
                }
            }
        }
        return dist;
    };

    vector<int> distS = getDist(s);
    vector<int> distE = getDist(e);
    int ans = distS[e];
    for (auto [u, v] : p) {
        int cur = min(distS[u] + 1 + distE[v], distS[v] + 1 + distE[u]);
        ans = min(ans, cur);
    }
    cout << ans << '\n';
    
    return 0;
}