#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int n;
    vector<int> mx, mn;
    vector<int> par, sz;
    
    DSU(int t_n) : n(t_n), par(t_n), sz(t_n), mx(t_n), mn(t_n) {
        iota(par.begin(), par.end(), 0);
        iota(mx.begin(), mx.end(), 0);
        iota(mn.begin(), mn.end(), 0);
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
        mn[pu] = min(mn[pv], mn[pu]);
        mx[pu] = max(mx[pv], mx[pu]);
        return true;
    }

    bool isSameParent(int u, int v) {
        return fpar(u) == fpar(v);
    }

    int getMn(int u) {
        return mn[fpar(u)];
    }

    int getMx(int u) {
        return mx[fpar(u)];
    }

    int getSize(int x) {
        int px = fpar(x);
        return sz[px];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    DSU L(n), R(n);

    auto check = [&](int i) -> bool {
        int cur = 0;
        int l = L.mn[L.fpar(i)] - 1;
        if (l >= 0) {
            cur += a[l];
        }
        int r = R.mx[R.fpar(i)] + 1;
        if (r < n) {
            cur += a[r];
        }
        return cur > d[i];
    };

    vector<int> st;
    for (int i = 0; i < n; i++) {
        if (check(i)) {
            st.emplace_back(i);
        }
    }
    vector<int> ans(n);
    for (int round = 0; round < n; round++) {
        ans[round] = (int) st.size();
        vector<int> cur;
        for (int p : st) {
            int l = L.mn[L.fpar(p)] - 1;
            int r = R.mx[R.fpar(p)] + 1;
            if (l >= 0) {
                R.merge(l, p);
                if (!binary_search(st.begin(), st.end(), l)) {
                    cur.emplace_back(l);
                }
            }
            if (r < n) {
                L.merge(p, r);
                if (!binary_search(st.begin(), st.end(), r)) {
                    cur.emplace_back(r);
                }
            }
        }
        sort(cur.begin(), cur.end());
        cur.resize(unique(cur.begin(), cur.end()) - cur.begin());
        st.clear();
        for (int p : cur) {
            if (check(p)) {
                st.emplace_back(p);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}