#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int n;
    vector<int> par, sz;
    
    DSU(int _n) : n(_n), par(_n), sz(_n) {
        iota(par.begin(), par.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    }

    int fpar(int x) {
        return (par[x] == x ? x : fpar(par[x]));
    }

    bool merge(int u, int v) {
        int pu = fpar(u), pv = fpar(v);
        if (pu == pv) return false;
        if (sz[pu] < sz[pv]) swap(pu, pv);
        par[pv] = pu;
        sz[pu] += sz[pv];
        return true;
    }

    bool check(int u, int v) {
        int pu = fpar(u);
        int pv = fpar(v);
        return pu == pv;
    }
};

void solve() {
    int n;
    vector<int> m(2);
    cin >> n;
    for (int it = 0; it < 2; it++) {
        cin >> m[it];
    }
    vector<DSU> dsu(2, DSU(n + 5));
    for (int it = 0; it < 2; it++) {
        for (int i = 0; i < m[it]; i++) {
            int u, v;
            cin >> u >> v;
            dsu[it].merge(u, v);
        }
    }
    vector<pair<int, int>> ans;
    for (int u = 1; u < n; u++) {
        for (int v = u + 1; v <= n; v++) {
            if (dsu[0].check(u, v) || dsu[1].check(u, v)) {
                continue;
            }
            ans.emplace_back(u, v);
            dsu[0].merge(u, v);
            dsu[1].merge(u, v);
        }
    }
    cout << ans.size() << '\n';
    for (auto& [u, v] : ans) {
        cout << u << ' ' << v << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}