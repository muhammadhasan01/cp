#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    
    BIT(int _n) : n(_n), bit(_n + 1) {}

    void add(int x, T val) {
        for ( ; x <= n; x += x & -x)
            bit[x] += val;
    }

    T get(int x) {
        T ret = 0;
        for ( ; x > 0; x -= x & -x)
            ret += bit[x];
        return ret;
    }

    T query(int l, int r) {
        return get(r) - get(l - 1);
    }
};

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
    vector<long long> a(n + 1);
    BIT<long long> bit(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        bit.add(i, a[i]);
    }
    DSU dsu(n + 5);

    auto melt = [&](int l, int r, int x) -> void {
        if (x == 1) {
            return;
        }
        for (int i = l; i <= r; ) {
            bit.add(i, -a[i]);
            a[i] = a[i] / x;
            bit.add(i, a[i]);
            if (a[i] == 0) {
                dsu.merge(i + 1, i);
            }
            i = dsu.fpar(i + 1);
        }
    };

    int q;
    cin >> q;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            melt(l, r, x);
        } else if (tp == 2) {
            int l, r;
            cin >> l >> r;
            cout << bit.query(l, r) << '\n';
        }
    }
    
    return 0;
}