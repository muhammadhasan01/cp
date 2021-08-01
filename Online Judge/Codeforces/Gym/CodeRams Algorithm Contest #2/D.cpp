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
    vector<vector<int>> a(m + 1, vector<int>(k + 1));
    DSU dsu(n + 5);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> a[i][j];
            if (j > 1) {
                dsu.merge(a[i][j], a[i][j - 1]);
            }
        }
    }
    int c;
    cin >> c;
    vector<int> pos(c + 1);
    set<int> st;
    for (int i = 1; i <= c; i++) {
        cin >> pos[i];
        st.emplace(pos[i]);
        if (i > 1) {
            dsu.merge(pos[i], pos[i - 1]);
        }
    }
    int sp = dsu.fpar(pos[1]);
    vector<int> v;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= k; j++) {
            int cp = dsu.fpar(a[i][j]);
            if (sp == cp && st.find(a[i][j]) == st.end()) {
                v.emplace_back(a[i][j]);
            }
        }
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    int len = v.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << v[i] << " \n"[i == len - 1];
    }

    return 0;
}