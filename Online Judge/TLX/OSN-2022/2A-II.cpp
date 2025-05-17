#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int n;
    vector<int> par, sz;
    vector<vector<int>> val;
    
    DSU(int t_n) : n(t_n), par(t_n), sz(t_n), val(t_n) {
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
        return true;
    }

    bool mergeValues(int u, int v) {
        int pu = fpar(u);
        int pv = fpar(v);
        if (pu == pv) {
            return false;
        }
        if ((int) val[pu].size() < (int) val[pv].size()) {
            swap(pu, pv);
        }
        for (int x : val[pv]) {
            val[pu].emplace_back(x);
        }
        val[pv].clear();
        par[pv] = pu;
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
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        dsu.merge(u, v);
    }
    int numComp = 0;
    for (int i = 0; i < n; i++) {
        if (dsu.fpar(i) == i) {
            numComp++;
        }
    }
    int need = 2 * (numComp - 1);
    if (need > n) {
        cout << -1 << '\n';
        return 0;
    }
    vector<tuple<int, int, int>> values(n);
    for (int i = 0; i < n; i++) {
        values[i] = {h[i], dsu.fpar(i), i};
    }
    // Take minimum of every component
    sort(values.begin(), values.end());
    vector<bool> done(n);
    vector<bool> marked(n);
    long long ans = 0;
    for (int i = 0; i < n && need > 0; i++) {
        auto [x, p, idx] = values[i];
        if (done[p]) {
            continue;
        }
        done[p] = true;
        marked[idx] = true;
        ans += x;
        need--;
    }
    // Take minimum of others
    for (int i = 0; i < n && need > 0; i++) {
        auto [x, p, idx] = values[i];
        if (marked[idx]) {
            continue;
        }
        marked[idx] = true;
        ans += x;
        need--;
    }
    if (q == 0) {
        cout << ans << '\n';
        return 0;
    }
    // Configure DSU values
    for (int i = 0; i < n; i++) {
        auto [x, p, idx] = values[i];
        if (!marked[idx]) {
            continue;
        }
        dsu.val[p].emplace_back(idx);
    }
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        if ((int) dsu.val[i].size() > 0) {
            st.emplace((int) dsu.val[i].size(), i);
        }
    }
    vector<pair<int, int>> edges;
    while (!st.empty()) {
        if ((int) st.size() == 1) {
            cout << -1 << '\n';
            return 0;
        }
        auto [sz_i, i] = *st.begin();
        auto [sz_j, j] = *prev(st.end());
        st.erase(st.begin());
        st.erase(prev(st.end()));
        int u = dsu.val[i].back();
        int v = dsu.val[j].back();
        dsu.val[i].pop_back();
        dsu.val[j].pop_back();
        edges.emplace_back(u, v);
        dsu.mergeValues(i, j);
        int new_sz = sz_i + sz_j - 2;
        if (new_sz > 0) {
            st.emplace(new_sz, dsu.fpar(i));
        }
    }
    cout << ans << '\n';
    cout << (int) edges.size() << '\n';
    for (auto [u, v] : edges) {
        cout << u + 1 << " " << v + 1 << '\n';
    }
    
    return 0;
}