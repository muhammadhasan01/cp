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
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    DSU dsu(n + 5);
    map<string, int> mp;
    for (int i = 0, id = 0; i < m; i++) {
        string u, v;
        cin >> u >> v;
        if (mp.count(u) == 0) {
            mp[u] = ++id;
        }
        if (mp.count(v) == 0) {
            mp[v] = ++id;
        }
        int nu = mp[u];
        int nv = mp[v];
        dsu.merge(nu, nv);
    }
    vector<int> comps;
    for (int u = 1; u <= n; u++) {
        if (dsu.fpar(u) != u) {
            continue;
        }
        comps.emplace_back(dsu.sz[u]);
    }
    sort(comps.rbegin(), comps.rend());
    int ans = 0;
    int len = comps.size();
    for (int i = 0; i < min(len, k); i++) {
        ans += comps[i];
    }
    cout << ans << '\n';

    return 0;
}