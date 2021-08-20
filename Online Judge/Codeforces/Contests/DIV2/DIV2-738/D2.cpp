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
        if (pu > pv) {
            swap(pu, pv);
        }
        par[pv] = pu;
        sz[pu] += sz[pv];
        return true;
    }

    bool same(int u, int v) {
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
    vector<DSU> dsu(2, DSU(n + 1));
    for (int it = 0; it < 2; it++) {
        for (int i = 0; i < m[it]; i++) {
            int u, v;
            cin >> u >> v;
            dsu[it].merge(u, v);
        }
    }
    vector<pair<int, int>> ans;
    vector<vector<int>> v(2);
    for (int x = 1; x <= 1; x++) {
        for (int y = 2; y <= n; y++) {
            if (!dsu[0].same(x, y) && !dsu[1].same(x, y)) {
                ans.emplace_back(x, y);
                dsu[0].merge(x, y);
                dsu[1].merge(x, y);
            }
            for (int it = 0; it < 2; it++) {
                if (dsu[it].fpar(y) != x) {
                    v[it].emplace_back(y);
                }
            }
        }
    }
    while (!v[0].empty() && !v[1].empty()) {
        vector<int> b(2);
        bool flag = false;
        for (int it = 0; it < 2; it++) {
            b[it] = v[it].back();
            if (dsu[0].fpar(b[it]) == 1 && dsu[1].fpar(b[it]) == 1) {
                v[it].pop_back();
                flag = true;
                break;
            }
        }
        if (flag) {
            continue;
        }
        ans.emplace_back(b[0], b[1]);
        dsu[0].merge(b[0], b[1]);
        dsu[1].merge(b[0], b[1]);
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