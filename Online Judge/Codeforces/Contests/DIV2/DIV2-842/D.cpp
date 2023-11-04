#include <bits/stdc++.h>

using namespace std;

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

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    int minSort = 0;
    vector<bool> vis(n + 1);
    DSU dsu(n + 1);
    for (int x = 1; x <= n; x++) {
        if (vis[x]) {
            continue;
        }
        int cycleSize = 0;
        while (!vis[x]) {
            vis[x] = true;
            dsu.merge(x, pos[x]);
            x = pos[x];
            ++cycleSize;
        }
        minSort += (cycleSize - 1);
    }
    for (int x = 2; x <= n; x++) {
        if (dsu.isSameParent(x - 1, x)) {
            cout << minSort - 1 << '\n';
            return;
        }
    }
    cout << minSort + 1 << '\n';
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