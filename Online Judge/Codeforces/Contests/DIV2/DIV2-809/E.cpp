#include <bits/stdc++.h>

using namespace std;

template<class Info, class Merge = plus<Info>>
struct SegmentTree {
    const int n;
    const Merge merge;
    vector<Info> t;
    SegmentTree(int len) : n(len), merge(Merge()), t(4 << __lg(len)) {}
    SegmentTree(vector<Info> init) : SegmentTree(init.size()) {
        function<void(int, int, int)> build = [&](int v, int s, int e) {
            if (s == e) {
                t[v] = init[s];
                return;
            }
            int mid = (s + e) >> 1;
            build(v << 1, s, mid);
            build(v << 1 | 1, mid + 1, e);
            pull(v);
        };
        build(1, 0, n - 1);
    }

    void pull(int v) {
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }

    void modify(int v, int s, int e, int pos, const Info &val) {
        if (s == e && s == pos) {
            t[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid) {
            modify(v << 1, s, mid, pos, val);
        } else {
            modify(v << 1 | 1, mid + 1, e, pos, val);
        }
        pull(v);
    }

    void modify(int p, const Info &v) {
        modify(1, 0, n - 1, p, v);
    }

    Info rangeQuery(int v, int s, int e, int l, int r) {
        if (e < l || s > r || l > r) {
            return Info();
        }
        if (l <= s && e <= r) {
            return t[v];
        }
        int mid = (s + e) >> 1;
        return merge(rangeQuery(v << 1, s, mid, l, r), rangeQuery(v << 1 | 1, mid + 1, e, l, r));
    }

    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n - 1, l, r);
    }
};

struct Info {
    int val;
    Info() : val(-INT_MAX) {}
    Info(int v) : val(v) {}
};

Info operator+(const Info& lhs, const Info& rhs) {
    return Info(max(lhs.val, rhs.val));
}

struct DSU {
    int n;
    vector<int> par, sz;
    vector<set<int>> st;
    
    DSU(int t_n) : n(t_n), par(t_n), sz(t_n), st(t_n) {
        for (int i = 0; i < t_n; i++) {
            st[i].emplace(i);
            par[i] = i;
            sz[i] = 1;
        }
    }

    int fpar(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = fpar(par[x]);
    }

    bool merge(int u, int v, vector<int>& a, int k) {
        int pu = fpar(u), pv = fpar(v);
        if (pu == pv) return false;
        if (sz[pu] < sz[pv]) swap(pu, pv);
        par[pv] = pu;
        sz[pu] += sz[pv];
        for (int x : st[pv]) {
            st[pu].emplace(x);
            auto it = st[pu].lower_bound(x);
            if (next(it) != st[pu].end() && *next(it) == x + 1) {
                a[x] = min(a[x], k);
            }
            if (it != st[pu].begin() && *prev(it) == x - 1) {
                a[x - 1] = min(a[x - 1], k);
            }
        }
        set<int>().swap(st[pv]);
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
    int n, m, q;
    cin >> n >> m >> q;
    DSU dsu(n + 1);
    vector<int> a(n + 1, m);
    for (int k = 1; k <= m; k++) {
        int u, v;
        cin >> u >> v;
        dsu.merge(u, v, a, k);
    }
    SegmentTree<Info> segtree(vector<Info>(a.begin(), a.end()));
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << 0 << ' ';
            continue;
        }
        cout << segtree.rangeQuery(l, r - 1).val << ' ';
    }
    cout << '\n';
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