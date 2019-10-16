#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pil;

int n, m, q;
const long long inf = 2e18;
vector<vector<pil>> g;
vector<vector<long long>> dist;

void djikstra(int u) {
    priority_queue<pil, vector<pil>, greater<pil>> pq;
    dist[u].resize(n + 3, inf);
    dist[u][u] = 0;
    pq.push({dist[u][u], u});
    while (!pq.empty()) {
        int x = pq.top().second;
        pq.pop();
        for (auto e : g[x]) {
            int y = e.first;
            long long w = e.second;
            if (dist[u][y] > dist[u][x] + w) {
                dist[u][y] = dist[u][x] + w;
                pq.push({dist[u][y], y});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    g.resize(n + 3);
    dist.resize(n + 3);
    for (int i = 1; i <= m; i++) {
        int u, v;
        long long t;
        cin >> u >> v >> t;
        u++, v++;
        g[u].push_back({v, t});
        g[v].push_back({u, t});
    }
    for (int i = 1; i <= n; i++) djikstra(i);
    for (int i = 1; i <= q; i++) {
        long long ans = 0;
        queue<long long> q;
        vector<bool> vis(n + 3, false);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto e : g[cur]) {

            }
        }
    }

    return 0;
}
