#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int n;
    vector<int> par, sz;
    vector<set<pair<int, int>>> st;
    
    DSU(int t_n) : n(t_n), par(t_n), sz(t_n), st(t_n) {
        iota(par.begin(), par.end(), 0);
        fill(sz.begin(), sz.end(), 1);
        for (int i = 0; i < t_n; i++) {
            st[i].emplace(i, 0);
        }
    }

    int fpar(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = fpar(par[x]);
    }

    bool merge(int u, int v, int z) {
        int pu = fpar(u);
        int pv = fpar(v);
        if (pu == pv) {
            return false;
        }
        if (sz[pu] < sz[pv]) {
            swap(pu, pv);
            swap(u, v);
            z = -z;
        }
        int cu = getValue(u);
        int cv = getValue(v);
        int dif = z + cu - cv;
        for (auto [x, val] : st[pv]) {
            st[pu].emplace(x, val + dif);
        }
        st[pv].clear();
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

    int getValue(int u) {
        int pu = fpar(u);
        return st[pu].lower_bound({u, -INT_MAX})->second;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    while (m--) {
        int u, v, z;
        cin >> u >> v >> z;
        dsu.merge(u, v, z);
    }
    if (dsu.isSameParent(1, n)) {
        cout << abs(dsu.getValue(1) - dsu.getValue(n)) << '\n';
    } else {
        cout << -1 << '\n';
    }
    
    return 0;
}