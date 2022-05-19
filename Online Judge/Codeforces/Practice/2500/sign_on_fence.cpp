#include <bits/stdc++.h>

using namespace std;

struct value {
    int ans, pre, suf;
    int tl, tr;
    value() : ans(0), pre(0), suf(0), tl(-1), tr(-1) { }
    value(int a, int p, int s, int l, int r) : ans(a), pre(p), suf(s), tl(l), tr(r) { }
    value(const value& v) {
        *this = v;
    }
};

value merge(value lhs, value rhs) {
    if (lhs.tl > rhs.tl) {
        swap(lhs, rhs);
    }
    if (lhs.tl == -1) {
        return rhs;
    }
    value ret;
    ret.ans = max({lhs.ans, rhs.ans, lhs.suf + rhs.pre});
    ret.pre = lhs.pre + (lhs.pre == lhs.tr - lhs.tl + 1 ? rhs.pre : 0);
    ret.suf = rhs.suf + (rhs.suf == rhs.tr - rhs.tl + 1 ? lhs.suf : 0);
    ret.tl = lhs.tl;
    ret.tr = rhs.tr;
    return ret;
}

struct vertex {
    value val;
    vertex *l, *r;
    vertex(value v) : val(v), l(NULL), r(NULL) { }
    vertex(vertex* l, vertex* r, int tl, int tr) : val(value()), l(l), r(r) {
        if (l) {
            val = merge(val, l->val);
        }
        if (r) {
            val = merge(val, r->val);
        }
        val.tl = tl;
        val.tr = tr;
    }  
};
typedef vertex* pvertex;

pvertex build(int s, int e) {
    if (s == e)
        return new vertex(value(0, 0, 0, s, e));
    int mid = (s + e) >> 1;
    return new vertex(build(s, mid), build(mid + 1, e), s, e);
}

pvertex update(pvertex v, int s, int e, int pos) {
    if (s == e && s == pos)
        return new vertex(value(1, 1, 1, s, e));
    int mid = (s + e) >> 1;
    if (pos <= mid)
        return new vertex(update(v->l, s, mid, pos), v->r, s, e);
    else
        return new vertex(v->l, update(v->r, mid + 1, e, pos), s, e);
}

value getQuery(pvertex v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return value();
    if (l <= s && e <= r) return v->val;
    int mid = (s + e) >> 1;
    value p1 = getQuery(v->l, s, mid, l, r);
    value p2 = getQuery(v->r, mid + 1, e, l, r);
    return merge(p1, p2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> h(n + 1);
    vector<pair<int, int>> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        p[i] = make_pair(h[i], i);
    }
    sort(p.begin() + 1, p.end());
    vector<pvertex> segtree(n + 2);
    segtree[n + 1] = build(1, n);
    for (int i = n; i >= 1; i--) {
        segtree[i] = update(segtree[i + 1], 1, n, p[i].second);
    }
    auto solve = [&](int tl, int tr, int w) {
        int l = 1, r = n, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (getQuery(segtree[mid], 1, n, tl, tr).ans >= w) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        return p[at].first;
    };
    int q;
    cin >> q;
    while (q--) {
        int l, r, w;
        cin >> l >> r >> w;
        cout << solve(l, r, w) << '\n';
    }
    
    return 0;
}