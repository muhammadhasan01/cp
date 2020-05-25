#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, int> pli;

const int N = 1e5 + 5;
const int ONE = N; // correspond to first segtree
const int TWO = 4 * N; // correspond to second segtree
const int TOTAL = 9 * N;
const long long INF = 1e18;

int n, q, s;
vector<pair<int, int>> adj[TOTAL];
long long dist[TOTAL];

void build(int v, int s, int e) {
    if (v > 1) {
        // Link to parent
        adj[v + TWO].emplace_back((v >> 1) + TWO, 0);
    }
    if (s == e) {
        // Link to real nodes
        adj[v + ONE].emplace_back(s, 0LL);
        adj[s].emplace_back(v + TWO, 0LL);
        return;
    }
    // Link to children
    adj[v + ONE].emplace_back((v << 1) + ONE, 0);
    adj[v + ONE].emplace_back((v << 1 | 1) + ONE, 0);
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
}

void update(int v, int s, int e, int l, int r, int u, int w, int op) {
    if (e < l || s > r) return;
    if (l <= s && e <= r) {
        if (op == 2) {
            adj[u].emplace_back(v + ONE, w);
        } else if (op == 3) {
            adj[v + TWO].emplace_back(u, w);
        }
        return;
    }
    int mid = (s + e) >> 1;
    update(v << 1, s, mid, l, r, u, w, op);
    update(v << 1 | 1, mid + 1, e, l, r, u, w, op);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q >> s;
    build(1, 1, n);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
        } else {
            int u, l, r, w;
            cin >> u >> l >> r >> w;
            update(1, 1, n, l, r, u, w, t);
        }
    }
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    fill(dist, dist + TOTAL, INF);
    dist[s] = 0;
    pq.emplace(dist[s], s);
    while (!pq.empty()) {
        pli cur = pq.top();
        pq.pop();
        long long cost = cur.first;
        int u = cur.second;
        if (cost > dist[u]) continue;
        for (auto e : adj[u]) {
            int v = e.first;
            int curcost = e.second;
            if (dist[u] + curcost < dist[v]) {
                dist[v] = dist[u] + curcost;
                pq.emplace(dist[v], v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) dist[i] = -1;
        cout << dist[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}