#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int n;
    vector<int> par, sz;
    vector<set<int>> st;
    
    DSU(int t_n) : n(t_n), par(t_n), sz(t_n), st(t_n) {
        iota(par.begin(), par.end(), 0);
        fill(sz.begin(), sz.end(), 1);
        for (int i = 0; i < t_n; i++) {
            st[i].emplace(i);
        }
    }

    int fpar(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = fpar(par[x]);
    }

    bool merge(int u, int v) {
        int pu = fpar(u);
        int pv = fpar(v);
        if (pu == pv) {
            return false;
        }
        if (sz[pu] < sz[pv]) {
            swap(pu, pv);
        }
        par[pv] = pu;
        sz[pu] += sz[pv];
        for (int x : st[pv]) {
            st[pu].emplace(x);
        }
        st[pv].clear();
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

void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> h(p);
    for (int i = 0; i < p; i++) {
        cin >> h[i];
    }
    vector<tuple<int, int, int>> edges(m);
    for (auto& [w, u, v] : edges) {
        cin >> u >> v >> w;
    }
    sort(edges.begin(), edges.end());
    vector dist(n + 1, vector(n + 1, 0LL));
    DSU dsu(n + 1);
    for (auto [w, u, v] : edges) {
        if (dsu.isSameParent(u, v)) {
            continue;
        }
        for (int x : dsu.st[dsu.fpar(u)]) {
            for (int y : dsu.st[dsu.fpar(v)]) {
                dist[x][y] = w;
                dist[y][x] = w;
            }
        }
        dsu.merge(u, v);
    }
    vector<int> ans(n + 1);
    vector<bool> vis(n + 1);
    vector<long long> dp(n + 1, LLONG_MAX);
    long long res = LLONG_MAX;
    for (int k = 1; k <= n; k++) {
        auto calc = [&](int i) -> long long {
            long long ret = 0;
            for (int u : h) {
                ret += min(dp[u], dist[u][h[i]]);
            }
            return ret;
        };

        auto upd = [&](int i) {
            for (int u : h) {
                dp[u] = min(dp[u], dist[u][h[i]]);
            }
        };

        if (k <= p) {
            int pos = -1;
            for (int i = 0; i < p; i++) {
                if (!vis[i]) {
                    long long cur = calc(i);
                    if (cur < res) {
                        res = cur;
                        pos = i;
                    }
                }
            }
            if (pos != -1) {
                vis[pos] = true;
                upd(pos);
            }
        }
        cout << res << " \n"[k == n];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}