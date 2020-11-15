#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int L = ceil(log2(N)) + 2;
const long long INF = 1e18;

using pli = pair<long long, int>;

int n, m, q;
vector<pair<int, int>> adj[N];
long long dist[N][N];

void dijsktra(int x) {
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dist[x][x] = 0;
    pq.emplace(dist[x][x], x);
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int u = cur.second;
        if (dist[x][u] != cur.first) continue;
        for (auto& e : adj[u]) {
            int v = e.first;
            long long w = e.second;
            if (dist[x][v] > dist[x][u] + w) {
                dist[x][v] = dist[x][u] + w;
                pq.emplace(dist[x][v], v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++) {
        dijsktra(i);
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << dist[l][r] << endl;
    }
    return 0;
}