#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int n;
    vector<int> par, sz;
    vector<set<pair<int, int>>> cur;
    
    DSU(int _n) : n(_n), par(_n), sz(_n) {
        iota(par.begin(), par.end(), 0);
        fill(sz.begin(), sz.end(), 1);
        cur.resize(_n);
    }

    int fpar(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = fpar(par[x]);
    }

    int getSize(int u) {
        int pu = fpar(u);
        return sz[pu];
    }

    bool merge(int u, int v) {
        int pu = fpar(u), pv = fpar(v);
        if (pu == pv) return false;
        if (sz[pu] < sz[pv]) swap(pu, pv);
        par[pv] = pu;
        sz[pu] += sz[pv];
        for (auto [x, y] : cur[pv]) {
            cur[pu].emplace(x, y);
        }
        cur[pv].clear();
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    DSU dsu(n + 1);
    vector<bool> vis(n + 1);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            q.emplace(i);
            vis[i] = true;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dsu.getSize(u) >= a[v]) {
                dsu.merge(u, v);
                while (true) {
                    int pu = dsu.fpar(u);
                    if (dsu.cur[pu].empty()) {
                        break;
                    }
                    auto [val, w] = *dsu.cur[pu].begin();
                    if (val > dsu.getSize(pu)) {
                        break;
                    }
                    dsu.cur[pu].erase(dsu.cur[pu].begin());
                    dsu.merge(pu, w);
                    if (!vis[w]) {
                        q.emplace(w);
                        vis[w] = true;
                    }
                }
                if (!vis[v]) {
                    q.emplace(v);
                    vis[v] = true;
                }
            } else {
                int pu = dsu.fpar(u);
                dsu.cur[pu].emplace(a[v], v);
            }
        }
    }
    cout << (dsu.getSize(1) == n ? "YES" : "NO") << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}