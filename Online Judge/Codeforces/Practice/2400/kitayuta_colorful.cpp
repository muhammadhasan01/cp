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

    bool check_same(int u, int v) {
        int pu = fpar(u), pv = fpar(v);
        return pu == pv;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjcol(n);
    vector<tuple<int, int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        auto& [u, v, w] = edges[i];
        cin >> u >> v >> w;
        --u, --v, --w;
        adjcol[u].emplace_back(w);
        adjcol[v].emplace_back(w);
    }
    vector<int> degsum(n + 1);
    for (int u = 0; u < n; u++) {
        sort(adjcol[u].begin(), adjcol[u].end());
        adjcol[u].resize(unique(adjcol[u].begin(), adjcol[u].end()) - adjcol[u].begin());
        degsum[u + 1] = degsum[u] + (int) adjcol[u].size();
    }
    auto get_pos = [&](const vector<int>& v, int node, int col) -> int {
        return degsum[node] + (lower_bound(v.begin(), v.end(), col) - v.begin());
    };
    DSU dsu(2 * m);
    for (int i = 0; i < m; i++) {
        auto [u, v, w] = edges[i];
        int x = get_pos(adjcol[u], u, w);
        int y = get_pos(adjcol[v], v, w);
        dsu.merge(x, y);
    }
    map<pair<int, int>, int> memo;
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if ((int) adjcol[u].size() > (int) adjcol[v].size()) {
            swap(u, v);
        }
        pair<int, int> nodep = make_pair(u, v);
        if (memo.count(nodep)) {
            cout << memo[nodep] << '\n';
            continue;
        }
        int ans = 0;
        for (int i = 0; i < (int) adjcol[u].size(); i++) {
            int col = adjcol[u][i];
            int upos = i + degsum[u];
            if (binary_search(adjcol[v].begin(), adjcol[v].end(), col)) {
                int vpos = get_pos(adjcol[v], v, col);
                if (dsu.check_same(upos, vpos)) {
                    ++ans;
                }
            }
        }
        cout << ans << '\n';
        memo[nodep] = ans;
    }
    
    return 0;
}