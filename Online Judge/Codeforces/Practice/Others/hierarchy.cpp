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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
    }
    int m;
    cin >> m;
    vector<tuple<int, int, int>> edges(m);
    for (auto& [w, u, v] : edges) {
        cin >> u >> v >> w;
    }
    sort(edges.begin(), edges.end());
    DSU dsu(n + 1);
    int cnt = 0;
    long long ans = 0;
    for (auto [w, u, v] : edges) {
        int pu = dsu.fpar(u);
        int pv = dsu.fpar(v);
        if (pu == pv) {
            continue;
        }
        dsu.merge(pu, pv);
        ans += w;
        if (++cnt == n - 1) {
            break;
        }
    }
    if (cnt < n - 1) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
    
    return 0;
}