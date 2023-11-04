#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int n;
    vector<int> par;
    
    DSU(int _n) : n(_n), par(_n) {
        iota(par.begin(), par.end(), 0);
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
        par[pv] = pu;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    vector<long long> ans(q + 1, -LLONG_MAX);
    vector<vector<tuple<int, int, int, int>>> queries(n + 1);
    for (int i = 1; i <= q; i++) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        queries[r].emplace_back(i, l, x, y);
    }
    for (int len = 1; len <= n; len++) {
        DSU dsu(n - len + 5);
        vector<long long> vals(n - len + 5, -LLONG_MAX);
        vector<pair<long long, int>> st;
        for (int r = len; r <= n; r++) {
            int l = r - len + 1;
            vals[l] = (a[r] - a[l - 1]);
            if (vals[l] < 0) {
                vals[l] = vals[l] / len - 1;
            } else {
                vals[l] /= len;
            }
            while (!st.empty() && st.back().first < vals[l]) {
                dsu.merge(l, st.back().second);
                st.pop_back();
            }
            st.emplace_back(vals[l], l);
            for (auto [pos, L, X, Y] : queries[r]) {
                if (len < X || len > Y) {
                    continue;
                }
                int parL = dsu.fpar(L);
                ans[pos] = max(ans[pos], vals[parL]);
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}