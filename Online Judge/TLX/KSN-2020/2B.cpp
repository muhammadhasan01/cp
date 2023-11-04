#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

struct DSU {
    int n;
    vector<int> par, sz;
    
    DSU(int t_n) : n(t_n), par(t_n), sz(t_n) {
        iota(par.begin(), par.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    }

    int fpar(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = fpar(par[x]);
    }

    bool merge(int u, int v) {
        int pu = fpar(u), pv = fpar(v);
        if (pu == pv) return false;
        if (sz[pu] < sz[pv]) swap(pu, pv);
        par[pv] = pu;
        sz[pu] += sz[pv];
        return true;
    }

    bool isSameParent(int u, int v) {
        return fpar(u) == fpar(v);
    }

    int getSize(int x) {
        int px = fpar(x);
        return sz[px];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<tuple<int, int, int>> X(n + 2); // [xl, xr, index]
    vector<tuple<int, int, int>> Y(n + 2); // [yl, yr, index]
    {
        int xs, ys, xf, yf;
        cin >> xs >> ys >> xf >> yf;
        X[0] = make_tuple(xs, xs, 0);
        X[n + 1] = make_tuple(xf, xf, n + 1);
        Y[0] = make_tuple(ys, ys, 0);
        Y[n + 1] = make_tuple(yf, yf, n + 1);
    }
    vector<int> c(n + 2);
    for (int i = 1; i <= n; i++) {
        int x, y, r;
        cin >> x >> y >> r >> c[i];
        X[i] = make_tuple(x - r, x + r, i);
        Y[i] = make_tuple(y - r, y + r, i);
    }
    int nodes = 2 * (n + 1) + 5;
    DSU dsu(nodes);
    // Horizontal
    sort(Y.begin(), Y.end());
    for (int i = 1, R = get<1>(Y[0]); i <= n + 1; i++) {
        if (R >= get<0>(Y[i])) {
            int l = get<2>(Y[i - 1]);
            int r = get<2>(Y[i]);
            dsu.merge(l, r);
        }
        R = max(R, get<1>(Y[i]));
    }
    // Vertical
    int add = n + 2;
    sort(X.begin(), X.end());
    for (int i = 1, R = get<1>(X[0]); i <= n + 1; i++) {
        if (R >= get<0>(X[i])) {
            int l = get<2>(X[i - 1]);
            int r = get<2>(X[i]);
            dsu.merge(l + add, r + add);
        }
        R = max(R, get<1>(X[i]));
    }
    vector<vector<pair<int, int>>> adj(nodes);
    for (int i = 1; i <= n; i++) {
        int h = dsu.fpar(i);
        int v = dsu.fpar(i + add);
        adj[h].emplace_back(v, c[i]);
        adj[v].emplace_back(h, c[i]);
    }
    vector<long long> dist(nodes, INF);
    priority_queue<pair<long long, int>> pq;
    int source = dsu.fpar(0);
    dist[source] = 0;
    pq.emplace(-dist[source], source);
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
    int targetH = dsu.fpar(n + 1);
    int targetV = dsu.fpar(n + 1 + add);
    long long res = min(dist[targetH], dist[targetV]);
    if (res == INF) {
        res = -1;
    }
    cout << res << '\n';
    
    return 0;
}