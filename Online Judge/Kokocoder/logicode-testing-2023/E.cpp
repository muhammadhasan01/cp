#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int n;
    vector<int> par, sz;
    vector<long long> cur;
    
    DSU(int _n) : n(_n), par(_n), sz(_n), cur(_n) {
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
        cur[pu] |= cur[pv];
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, t;
        long long w;
        cin >> u >> v >> t >> w;
        if (t == 1) {
            continue;
        }
        int pu = dsu.fpar(u);
        int pv = dsu.fpar(v);
        dsu.cur[pu] |= w;
        dsu.cur[pv] |= w;
        dsu.merge(pu, pv);
    }
    long long mx = 0;
    int sz = 0;
    for (int u = 1; u <= n; u++) {
        int pu = dsu.fpar(u);
        if (pu != u) {
            continue;
        }
        if (dsu.cur[pu] > mx) {
            mx = dsu.cur[pu];
            sz = dsu.sz[pu];
        } else if (dsu.cur[pu] == mx && sz < dsu.sz[pu]) {
            sz = dsu.sz[pu];
        }
    }
    cout << mx << " " << (mx == 0 ? n : sz) << '\n';
    
    return 0;
}