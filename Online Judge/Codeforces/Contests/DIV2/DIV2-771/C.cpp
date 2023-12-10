#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int n;
    vector<int> par, sz;
    
    DSU(int t_n) : n(t_n), par(t_n), sz(t_n) {
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
        int pu = fpar(u), pv = fpar(v);
        if (pu == pv) return false;
        if (sz[pu] < sz[pv]) swap(pu, pv);
        par[pv] = pu;
        sz[pu] += sz[pv];
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

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    set<int> st;
    for (int i = 1; i <= n; i++) {
        st.emplace(i);
    }
    st.emplace(n + 1);
    DSU dsu(n + 1);
    vector<bool> done(n + 1);
    for (int x = n; x >= 1; x--) {
        if (done[p[x]]) {
            st.erase(p[x]);
            continue;
        }
        int i = p[x];
        while (1) {
            i = *st.upper_bound(i);
            if (i > n) {
                break;
            }
            dsu.merge(p[x], i);
            if (done[i]) {
                break;
            }
            done[i] = true;
        }
        st.erase(p[x]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dsu.fpar(i) == i) {
            ++ans;
        }
    }
    cout << ans << '\n';
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