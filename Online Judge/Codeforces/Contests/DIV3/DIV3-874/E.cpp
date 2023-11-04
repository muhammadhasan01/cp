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
};

void solve() {
    int n;
    cin >> n;
    DSU dsu(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<bool> exist(n + 1);
    for (int i = 1; i <= n; i++) {
        dsu.merge(i, a[i]);
    }
    int mx = 0;
    vector<int> comp;
    for (int i = 1; i <= n; i++) {
        int pi = dsu.fpar(i);
        if (i == pi) {
            ++mx;
            comp.emplace_back(i);
        }
        if (a[a[i]] == i) {
            exist[pi] = true;
        }
    }
    int cnt = 0;
    for (int pi : comp) {
        if (!exist[pi]) {
            ++cnt;
        }
    }
    int mn = (cnt == mx ? mx : cnt + 1);
    cout << mn << ' ' << mx << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}