#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int n;
    vector<set<pair<int, long long>>> st;
    vector<int> par, sz;
    
    DSU(int t_n) : n(t_n), par(t_n), sz(t_n), st(t_n) {
        iota(par.begin(), par.end(), 0);
        fill(sz.begin(), sz.end(), 1);
        for (int i = 0; i < t_n; i++) {
            st[i].emplace(i, 0LL);
        }
    }

    int fpar(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = fpar(par[x]);
    }

    bool merge(int u, int v, int cost) {
        int pu = fpar(u), pv = fpar(v);
        if (pu == pv) return false;
        if (sz[pu] < sz[pv]) {
            swap(pu, pv);
            swap(u, v);
            cost = -cost;
        }
        auto [i1, v1] = *st[pu].lower_bound({u, -INT_MAX});
        auto [i2, v2] = *st[pv].lower_bound({v, -INT_MAX});
        par[pv] = pu;
        sz[pu] += sz[pv];
        for (auto& [i, val] : st[pv]) {
            st[pu].emplace(i, val - v2 + v1 + cost);
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    DSU dsu(n + 5);
    for (int i = 1; i <= q; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        if (!dsu.isSameParent(a, b)) {
            dsu.merge(a, b, d);
            cout << i << " ";
        } else {
            int p = dsu.fpar(a);
            auto [i1, v1] = *dsu.st[p].lower_bound({a, -INT_MAX});
            auto [i2, v2] = *dsu.st[p].lower_bound({b, -INT_MAX});
            if (v2 - v1 != d) {
                continue;
            }
            cout << i << " ";
        }
    }
    cout << '\n';
    
    return 0;
}