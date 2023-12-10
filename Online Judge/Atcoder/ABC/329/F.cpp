#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int n;
    vector<set<int>> st;
    vector<int> par, sz;
    
    DSU(int t_n) : n(t_n), par(t_n), sz(t_n), st(t_n) {
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
        if (sz[pu] < sz[pv]) {
            swap(pu, pv);
            swap(u, v);
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    DSU dsu(n + 1);
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        dsu.st[i].emplace(c);
    }
    vector<int> pos(n + 1);
    iota(pos.begin(), pos.end(), 0);
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (pos[a] != 0 && pos[b] != 0) {
            dsu.merge(pos[a], pos[b]);
        }
        if (pos[a] != 0) {
            pos[b] = pos[a];
            pos[a] = 0;
        }
        int pp = dsu.fpar(pos[b]);
        cout << dsu.st[pp].size() << '\n';
    }
    
    return 0;
}