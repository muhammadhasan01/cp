#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct compresser {
    vector<T> nums;
    
    compresser() { }

    compresser(vector<T>& v) {
        nums.assign(v.begin(), v.end());
        finish();
    }
 
    void add(T x) {
        nums.emplace_back(x);
    }
 
    void finish() {
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    }
 
    int get_id(T x) {
        return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
    }

    int get_val(int id) {
        return nums[id - 1];
    }
 
    int get_len() {
        return nums.size();
    }
};

const int INF = 2e9;
const int N = 5e4 + 5;

struct value {
    int bmax;
    int bmin;
    int amax;
    int amin;
    int abmax;
    int abmin;
    int bamax;
    int bamin;
    int bcount;
    int dif;
    value(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) :
        bmax(a), bmin(b), amax(c), amin(d), abmax(e), abmin(f), bamax(g), bamin(h), bcount(i), dif(j) { } 
};

value merge(value a, value b) {
    return value(
        max(a.bmax, b.bmax),
        min(a.bmin, b.bmin),
        max(a.amax, b.amax),
        min(a.amin, b.amin),
        max(a.abmax, b.abmax),
        min(a.abmin, b.abmin),
        max(a.bamax, b.bamax),
        min(a.bamin, b.bamin),
        a.bcount + b.bcount,
        min(a.dif, b.dif)
    );
}

const value TERM = value(-INF, INF, -INF, INF, -INF, INF, -INF, INF, 0, INF);

struct vertex {
    value val;
    vertex *l, *r;
    vertex(value val) : val(val), l(NULL), r(NULL) { }
    vertex(vertex* l, vertex* r) : val(TERM), l(l), r(r) {
        if (l) val = merge(val, l->val);
        if (r) val = merge(val, r->val);
    }
};
typedef vertex* pvertex;

int n, q;
int a[N], b[N];
tuple<int, int, int> p[N];
pvertex psegtree[N], ssegtree[N];

pvertex build(int s, int e) {
    if (s == e)
        return new vertex(TERM);
    int mid = (s + e) >> 1;
    return new vertex(build(s, mid), build(mid + 1, e));
}

pvertex update(pvertex v, int s, int e, int pos, value val) {
    if (s == e && s == pos)
        return new vertex(val);
    int mid = (s + e) >> 1;
    if (pos <= mid)
        return new vertex(update(v->l, s, mid, pos, val), v->r);
    else
        return new vertex(v->l, update(v->r, mid + 1, e, pos, val));
}

value getQuery(pvertex v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return TERM;
    if (l <= s && e <= r) return v->val;
    int mid = (s + e) >> 1;
    value p1 = getQuery(v->l, s, mid, l, r);
    value p2 = getQuery(v->r, mid + 1, e, l, r);
    return merge(p1, p2);
}

int getCount(pvertex v, pvertex w, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return 0;
    if (l <= s && e <= r) return w->val.bcount - v->val.bcount;
    int mid = (s + e) >> 1;
    int p1 = getCount(v->l, w->l, s, mid, l, r);
    int p2 = getCount(v->r, w->r, mid + 1, e, l, r);
    return p1 + p2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    compresser<int> cc;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cc.add(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        cc.add(b[i]);
    }
    cc.finish();
    for (int i = 1; i <= n; i++) {
        p[i] = make_tuple(cc.get_id(a[i]), cc.get_id(b[i]), i);
    }
    sort(p + 1, p + 1 + n);
    vector<int> ids(n + 1);
    int len_unique = cc.get_len();
    int m = 2 * n + 5;
    {
        psegtree[0] = build(0, m);
        unordered_map<int, int> mp;
        vector<value> dp(m + 5, TERM);
        for (int i = 1; i <= n; i++) {
            auto [x, y, id] = p[i];
            int vx = cc.get_val(x);
            int vy = cc.get_val(y);
            ids[id] = i;
            value cur(
                vy,
                vy,
                vx,
                vx,
                vx + vy,
                vx + vy,
                vx - vy,
                vx - vy,
                1,
                vy - vx
            );
            dp[y] = merge(dp[y], cur);
            psegtree[i] = update(psegtree[i - 1], 0, m, y, dp[y]);
        }
    }
    {
        ssegtree[n + 1] = build(0, m);
        unordered_map<int, int> mp;
        vector<value> dp(m + 5, TERM);
        for (int i = n; i >= 1; i--) {
            auto [x, y, id] = p[i];
            int vx = cc.get_val(x);
            int vy = cc.get_val(y);
            value cur(
                vy,
                vy,
                vx,
                vx,
                vx + vy,
                vx + vy,
                vx - vy,
                vx - vy,
                1,
                vy - vx
            );
            dp[y] = merge(dp[y], cur);
            ssegtree[i] = update(ssegtree[i + 1], 0, m, y, dp[y]);
        }
    }
    auto solve = [&](int l, int r) {
        int ans = INF;
        int amn = get<0>(p[l]);
        int amx = get<0>(p[r]);
        assert(amn <= amx);
        int vamn = cc.get_val(amn);
        int vamx = cc.get_val(amx);
        int bmn = get<1>(p[l]);
        int bmx = get<1>(p[r]);
        if (bmn > bmx) {
            swap(bmn, bmx);
        }
        int vbmn = cc.get_val(bmn);
        int vbmx = cc.get_val(bmx);
        // try [1, ..., l - 1]
        if (l > 1) {
            // left -> OK
            value lft = getQuery(psegtree[l - 1], 0, m, 1, bmn);
            if (lft.abmax != -INF) {
                ans = min(ans, vamx + vbmx - lft.abmax);
            }
            // mid -> OK
            value mid = getQuery(psegtree[l - 1], 0, m, bmn, bmx);
            if (mid.amax != -INF) {
                ans = min(ans, vamx + vbmx - mid.amax - vbmn);
            }
            // right -> OK
            value rgt = getQuery(psegtree[l - 1], 0, m, bmx, m);
            if (rgt.dif != INF) {
                ans = min(ans, vamx - vbmn + rgt.dif);
            }
        }
        // try [l + 1, ..., r - 1]
        if (r - l > 1) {
            // left
            {
                int lt = 1, rt = bmn, at = -1;
                while (lt <= rt) {
                    int mid = (lt + rt) >> 1;
                    if (getCount(psegtree[l], psegtree[r - 1], 0, m, mid, bmn) > 0) {
                        lt = mid + 1;
                        at = mid;
                    } else {
                        rt = mid - 1;
                    }
                }
                if (at != -1) {
                    ans = min(ans, vamx - vamn + vbmx - cc.get_val(at));
                }
            }
            // mid
            {
                if (getCount(psegtree[l], psegtree[r - 1], 0, m, bmn, bmx) > 0) {
                    ans = min(ans, vamx - vamn + vbmx - vbmn);
                }
            }
            // right
            {
                int lt = bmx, rt = len_unique, at = -1;
                while (lt <= rt) {
                    int mid = (lt + rt) >> 1;
                    if (getCount(psegtree[l], psegtree[r - 1], 0, m, bmx, mid) > 0) {
                        rt = mid - 1;
                        at = mid;
                    } else {
                        lt = mid + 1;
                    }
                }
                if (at != -1) {
                    ans = min(ans, vamx - vamn + cc.get_val(at) - vbmn);
                }
            }
        }
        // try [r + 1, ..., n]
        if (r < n) {
            // left -> OK
            value lft = getQuery(ssegtree[r + 1], 0, m, 1, bmn);
            if (lft.bamin != INF) {
                ans = min(ans, vbmx + lft.bamin - vamn);
            }
            // mid -> OK
            value mid = getQuery(ssegtree[r + 1], 0, m, bmn, bmx);
            if (mid.amin != INF) {
                ans = min(ans, vbmx - vbmn + mid.amin - vamn);
            }
            // right -> OK
            value rgt = getQuery(ssegtree[r + 1], 0, m, bmx, m);
            if (rgt.abmin != INF) {
                ans = min(ans, rgt.abmin - vbmn - vamn);
            }
        }
        cout << ans << '\n';
    };
    while (q--) {
        int l, r;
        cin >> l >> r;
        l = ids[l];
        r = ids[r];
        if (l > r) {
            swap(l, r);
        }
        solve(l, r);
    }

    return 0;
}