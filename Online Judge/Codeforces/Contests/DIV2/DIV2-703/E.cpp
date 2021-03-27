#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const int N = 1e5 + 5;
const int W = 55;

int n, m;
vector<pair<int, int>> adj[N];
long long dist[N][W];

void djikstra(int s) {
    priority_queue<tuple<long long, int, int>> pq;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < W; j++) {
            dist[i][j] = INF;
        }
    }
    dist[s][0] = 0;
    pq.emplace(-dist[s][0], s, 0);
    while (!pq.empty()) {
        long long d; int u; int cw;
        tie(d, u, cw) = pq.top();
        pq.pop();
        d = -d;
        if (dist[u][cw] != d) continue;
        for (auto& e : adj[u]) {
            int v = e.first;
            int w = e.second;
            if (cw == 0) {
                if (dist[v][w] > d) {
                    dist[v][w] = d;
                    pq.emplace(-dist[v][w], v, w);
                }
            } else {
                long long cur = 1LL * (cw + w) * (cw + w);
                if (dist[v][0] > d + cur) {
                    dist[v][0] = d + cur;
                    pq.emplace(-dist[v][0], v, 0);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    djikstra(1);
    for (int i = 1; i <= n; i++) {
        long long ans = dist[i][0];
        if (ans == INF) ans = -1;
        cout << ans << " \n"[i == n];
    }

    return 0;
}