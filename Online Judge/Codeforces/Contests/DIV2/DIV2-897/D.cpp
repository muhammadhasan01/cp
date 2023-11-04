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
    int n, k;
    cin >> n >> k;
    DSU dsu(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dsu.merge(i, a[i]);
    }
    if (k == 1) {
        for (int i = 1; i <= n; i++) {
            if (a[i] != i) {
                cout << "NO" << '\n';
                return;
            }
        }
        cout << "YES" << '\n';
        return;
    }
    vector<bool> vis(n + 1);
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        int p = dsu.fpar(i);
        if (vis[p]) {
            continue;
        }
        vis[p] = true;
        int u = i;
        cnt[u] = 1;
        int cycleSize = 0;
        while (true) {
            if (cnt[a[u]] > 0) {
                cycleSize = abs(cnt[a[u]] - cnt[u]) + 1;
                break;
            } else {
                cnt[a[u]] = cnt[u] + 1;
                u = a[u];
            }
        }
        if (cycleSize != k) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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