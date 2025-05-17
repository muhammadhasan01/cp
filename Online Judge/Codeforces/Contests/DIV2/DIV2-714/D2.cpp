#include <bits/stdc++.h>

using namespace std;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

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

void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    min_heap<pair<int, int>> heap;
    for (int i = 0; i + 1 < n; i++) {
        int mn = min(a[i], a[i + 1]);
        if (mn > p) {
            continue;
        }
        if (__gcd(a[i], a[i + 1]) == mn) {
            heap.emplace(mn, i);
        }
    }
    long long ans = 0;
    DSU dsu(n);
    while (!heap.empty()) {
        auto [val, i] = heap.top();
        heap.pop();
        if (dsu.isSameParent(i, i + 1)) {
            continue;
        }
        dsu.merge(i, i + 1);
        ans += val;
        if (i + 2 < n && !dsu.isSameParent(i + 1, i + 2) && __gcd(val, a[i + 2]) == val) {
            heap.emplace(val, i + 1);
        }
        if (i - 1 >= 0 && !dsu.isSameParent(i - 1, i) && __gcd(val, a[i - 1]) == val) {
            heap.emplace(val, i - 1);
        }
    }
    for (int i = 0; i + 1 < n; i++) {
        if (!dsu.isSameParent(i, i + 1)) {
            ans += p;
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