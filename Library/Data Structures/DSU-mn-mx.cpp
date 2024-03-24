struct DSU {
    int n;
    vector<int> mx, mn;
    vector<int> par, sz;
    
    DSU(int t_n) : n(t_n), mx(t_n), mn(t_n), par(t_n), sz(t_n) {
        iota(par.begin(), par.end(), 0);
        iota(mx.begin(), mx.end(), 0);
        iota(mn.begin(), mn.end(), 0);
        fill(sz.begin(), sz.end(), 1);
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
        mn[pu] = min(mn[pv], mn[pu]);
        mx[pu] = max(mx[pv], mx[pu]);
        return true;
    }

    bool isSameParent(int u, int v) {
        return fpar(u) == fpar(v);
    }

    int getMn(int u) {
        return mn[fpar(u)];
    }

    int getMx(int u) {
        return mx[fpar(u)];
    }

    int getSize(int x) {
        int px = fpar(x);
        return sz[px];
    }
};