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
    DSU dsu(n);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        dsu.merge(u, v);
    }
    vector<vector<int>> comp(n);
    for (int i = 0; i < n; i++) {
        comp[dsu.fpar(i)].emplace_back(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (comp[i].empty()) {
            continue;
        }
        int len = comp[i].size();
        map<int, int> mp;
        for (int x : comp[i]) {
            mp[c[x]]++;
        }
        pair<int, int> take = make_pair(-1, -1);
        for (auto& [v, cnt] : mp) {
            take = max(take, make_pair(cnt, v));
        }
        int chosen = take.second;
        for (int x : comp[i]) {
            if (c[x] == chosen) {
                continue;
            }
            ans++;
        }
    }
    cout << ans << '\n';
    
    return 0;
}