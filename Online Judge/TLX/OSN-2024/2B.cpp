#include <bits/stdc++.h>

using namespace std;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k, t, p, q;
    cin >> n >> m >> k >> t >> p >> q;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<vector<int>> in(n + 1);
    vector<vector<int>> out(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        adj[a].emplace_back(b, d);
        adj[b].emplace_back(a, d);
        in[a].emplace_back(c);
        out[b].emplace_back(c);
    }
    vector<int> nxt(n + 1, -1);
    multiset<int> ms;
    for (int x = 1; x < n; x++) {
        for (int val : in[x]) {
            ms.emplace(val);
        }
        for (int val : out[x]) {
            ms.erase(ms.find(val));
        }
        if (!ms.empty()) {
            nxt[x] = *ms.begin();
        }
    }
    min_heap<tuple<long long, int, int>> heap;
    vector dist(n + 1, vector(2, INF));
    dist[p][0] = 0;
    heap.emplace(dist[p][0], p, 0);
    while (!heap.empty()) {
        auto [dst, u, s] = heap.top();
        heap.pop();
        if (dst != dist[u][s]) {
            continue;
        }
        if (s == 0) {
            if (nxt[u] != -1 || nxt[u - 1] != -1) {
                if (dist[u][1] > dist[u][0] + t) {
                    dist[u][1] = dist[u][0] + t;
                    heap.emplace(dist[u][1], u, 1);
                }
            }
            if (u - 1 >= 1 && dist[u - 1][0] > dist[u][0] + k) {
                dist[u - 1][0] = dist[u][0] + k;
                heap.emplace(dist[u - 1][0], u - 1, 0);
            }
            if (u + 1 <= n && dist[u + 1][0] > dist[u][0] + k) {
                dist[u + 1][0] = dist[u][0] + k;
                heap.emplace(dist[u + 1][0], u + 1, 0);
            }
        } else if (s == 1) {
            if (dist[u][0] > dist[u][1]) {
                dist[u][0] = dist[u][1];
                heap.emplace(dist[u][0], u, 0);
            }
            if (nxt[u] != -1 && dist[u + 1][1] > dist[u][1] + nxt[u]) {
                dist[u + 1][1] = dist[u][1] + nxt[u];
                heap.emplace(dist[u + 1][1], u + 1, 1);
            }
            if (u - 1 >= 1 && nxt[u - 1] != -1 && dist[u - 1][1] > dist[u][1] + nxt[u - 1]) {
                dist[u - 1][1] = dist[u][1] + nxt[u - 1];
                heap.emplace(dist[u - 1][1], u - 1, 1);
            }
            for (auto [v, w] : adj[u]) {
                if (dist[v][1] > dist[u][1] + w) {
                    dist[v][1] = dist[u][1] + w;
                    heap.emplace(dist[v][1], v, 1);
                }
            }
        }
    }
    cout << min(dist[q][0], dist[q][1]) << '\n';
    
    return 0;
}