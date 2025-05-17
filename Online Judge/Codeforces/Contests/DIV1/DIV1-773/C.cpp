#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int n;
    vector<int> mx, mn;
    vector<int> par, sz;
    
    DSU(int t_n) : n(t_n), mx(t_n), mn(t_n), par(t_n), sz(t_n) {
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

    bool merge(int u, int v, vector<int>& cond) {
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
        cond[pu] = 0;
        cond[pv] = 0;
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
            t[v] = merge(t[v], val);
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
    Info() : val(INT_MAX) {}
    Info(int v) : val(v) {}
};

Info operator+(const Info& lhs, const Info& rhs) {
    return Info(min(lhs.val, rhs.val));
}

void solve() {
    int n, q;
    cin >> n >> q;
    DSU dsu(n + 1);
    vector<int> condition(n + 1, -1);
    SegmentTree<Info> segtree(n + 1);
    set<int> checks;
    for (int i = 0; i < q; i++) {
        int tp;
        cin >> tp;
        if (tp == 0) {
            int l, r, x;
            cin >> l >> r >> x;
            if (x == 0) {
                condition[dsu.fpar(l)] = 0;
                {
                    int pos = dsu.getMx(l);
                    while (pos + 1 <= r) {
                        dsu.merge(pos, pos + 1, condition);
                        pos = dsu.getMx(pos);
                    }
                }
                {
                    int pos = dsu.getMx(r);
                    while (pos + 1 <= n && condition[dsu.fpar(pos + 1)] == 0) {
                        dsu.merge(pos, pos + 1, condition);
                        pos = dsu.getMx(pos);
                    }
                }
                {
                    int pos = dsu.getMn(l);
                    while (pos - 1 >= 1 && condition[dsu.fpar(pos - 1)] == 0) {
                        dsu.merge(pos - 1, pos, condition);
                        pos = dsu.getMn(pos);
                    }
                }
                checks.emplace(dsu.getMn(l) - 1);
                checks.emplace(dsu.getMx(r) + 1);
            } else {
                segtree.modify(l, r);
                checks.emplace(l);
                checks.emplace(r);
                if (condition[dsu.fpar(l)] == 0) {
                    checks.emplace(dsu.getMn(l) - 1);
                    checks.emplace(dsu.getMx(l) + 1);
                }
                if (condition[dsu.fpar(r)] == 0) {
                    checks.emplace(dsu.getMn(r) - 1);
                    checks.emplace(dsu.getMx(r) + 1);
                }
            }
        } else {
            for (int pos : checks) {
                if (pos < 1 || pos > n || condition[dsu.fpar(pos)] == 0) {
                    continue;
                }
                int lft = pos;
                if (pos - 1 >= 1 && condition[dsu.fpar(pos - 1)] == 0) {
                    lft = dsu.getMn(pos - 1);
                }
                int mostLeft = segtree.rangeQuery(lft, pos).val;
                int rgt = pos;
                if (pos + 1 <= n && condition[dsu.fpar(pos + 1)] == 0) {
                    rgt = dsu.getMx(pos + 1);
                }
                if (rgt >= mostLeft && mostLeft >= pos) {
                    condition[pos] = 1;
                }
            }
            checks.clear();
            int j;
            cin >> j;
            j = dsu.fpar(j);
            if (condition[j] == -1) {
                cout << "N/A" << '\n';
            } else if (condition[j] == 0) {
                cout << "NO" << '\n';
            } else {
                cout << "YES" << '\n';
            }
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}