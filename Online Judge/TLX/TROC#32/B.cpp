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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            continue;
        }
        int j = (i + 1) % n;
        if (a[j] == 0) {
            continue;
        }
        dsu.merge(i, j);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            continue;
        }
        int p = dsu.fpar(i);
        if (i == p) {
            int sz = dsu.sz[i];
            ans += 1LL * sz * (sz + 1) / 2;
        }
    }
    cout << ans << '\n';

    return 0;
}