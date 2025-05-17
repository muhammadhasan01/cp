#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

struct DSU {
    int n;
    vector<int> par, sz;
    vector<deque<pair<long long, int>>> values;
    
    DSU(int n) : n(n), par(n), sz(n), values(n) {
        iota(par.begin(), par.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    }

    int fpar(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = fpar(par[x]);
    }

    int getSize(int u) {
        int pu = fpar(u);
        return sz[pu];
    }

    bool merge(int u, int v) {
        int pu = fpar(u), pv = fpar(v);
        if (pu == pv) return false;
        if (sz[pu] < sz[pv]) swap(pu, pv);
        par[pv] = pu;
        sz[pu] += sz[pv];
        for (auto [val, pos] : values[pv]) {
            values[pu].emplace_back(val, pos);
        }
        values[pv].clear();
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        long long h;
        cin >> h;
        dsu.values[i].emplace_back(h, i);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        dsu.merge(u, v);
    }
    int numComponent = 0;
    vector<int> comps;
    for (int u = 0; u < n; u++) {
        if (dsu.fpar(u) == u) {
            numComponent++;
            comps.emplace_back(u);
        }
    }
    vector<pair<long long, int>> smallest;
    for (int i = 0; i < numComponent; i++) {
        int u = comps[i];
        deque<pair<long long, int>>& values = dsu.values[u];
        int len = values.size();
        if (len <= 1) {
            continue;
        }
        sort(values.begin(), values.end());
        for (int j = 1; j < len; j++) {
            smallest.emplace_back(values[j].first, i);
        }
    }
    sort(smallest.begin(), smallest.end());
    int need = numComponent - 2;
    vector<int> cnt(numComponent, 1);
    for (auto [_, pos] : smallest) {
        if (need == 0) {
            break;
        }
        cnt[pos]++;
        need--;
    }
    set<pair<int, int>> compSt;
    for (int i = 0; i < numComponent; i++) {
        compSt.emplace(cnt[i], comps[i]);
    }
    long long cost = 0;
    vector<pair<int, int>> edges;
    while ((int) compSt.size() >= 2) {
        auto U = compSt.begin();
        auto V = prev(compSt.end());
        auto [cu, u] = *U;
        auto [cv, v] = *V;
        auto [valU, posU] = dsu.values[u].front();
        auto [valV, posV] = dsu.values[v].front();
        cost += valU + valV;
        edges.emplace_back(posU, posV);
        dsu.values[u].pop_front();
        dsu.values[v].pop_front();
        compSt.erase(V);
        compSt.erase(U);
        if (cu > 1) {
            compSt.emplace(cu - 1, u);
        }
        if (cv > 1) {
            compSt.emplace(cv - 1, v);
        }
    }
    for (auto [u, v] : edges) {
        dsu.merge(u, v);
    }
    if (dsu.getSize(0) < n) {
        cout << -1 << '\n';
        return 0;
    }
    cout << cost << '\n';
    if (q == 1) {
        cout << edges.size() << '\n';
        for (auto [u, v] : edges) {
            cout << u + 1 << ' ' << v + 1 << '\n';
        }
    }

    return 0;
}