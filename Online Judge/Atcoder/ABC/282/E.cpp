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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sz = n * (n - 1) / 2;
    vector<tuple<int, int, int>> edges(sz);

    auto binpow = [&](long long x, long long y) -> int {
        long long ret = 1;
        while (y > 0) {
            if (y & 1) {
                ret = (ret * x) % m;
            }
            y >>= 1;
            x = (x * x) % m;
        }
        return ret;
    };

    auto compute = [&](int i, int j) -> int {
        return (binpow(a[i], a[j]) + binpow(a[j], a[i])) % m;
    };

    for (int i = 0, c = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges[c++] = make_tuple(compute(i, j), i, j);
        }
    }
    sort(edges.rbegin(), edges.rend());
    DSU dsu(n);
    long long ans = 0;
    int cnt = 0;
    for (auto [w, u, v] : edges) {
        if (dsu.merge(u, v)) {
            ans += w;
            if (++cnt == n - 1) {
                break;
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}