#include <bits/stdc++.h>

using namespace std;

template<int MAXN, typename T, const T& TERM>
struct Segtree {
    vector<T> t;
    Segtree() {
        t.assign(4 * (MAXN + 5), TERM);
    }

    T combine(const T& x, const T& y) {
        return x + y;
    }

    void build(int v, int s, int e) {
        if (s == e) {
            t[v] = 0;
        } else {
            int mid = (s + e) >> 1;
            build(v << 1, s, mid);
            build(v << 1 | 1, mid + 1, e);
            t[v] = combine(t[v << 1], t[v << 1 | 1]);
        }
    }

    void update(int v, int s, int e, int pos, T val) {
        if (s == e && s == pos) {
            t[v] += val;
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid)
            update(v << 1, s, mid, pos, val);
        else
            update(v << 1 | 1, mid + 1, e, pos, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    T get(int v, int s, int e, int l, int r) {
        if (e < l || s > r || l > r)
            return TERM;
        if (l <= s && e <= r)
            return t[v];
        int mid = (s + e) >> 1;
        T p1 = get(v << 1, s, mid, l, r);
        T p2 = get(v << 1 | 1, mid + 1, e, l, r);
        return combine(p1, p2);
    }
};

const int N = 1e6;
const int TERM = 0;
Segtree<N, int, TERM> sgt_x, sgt_y;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<int> y(m);
    for (int i = 0; i < m; i++) {
        cin >> y[i];
    }
    long long res = 0;
    vector<pair<int, int>> points(k);
    for (int i = 0; i < k; i++) {
        auto& [p, q] = points[i];
        cin >> p >> q;
    }
    sort(points.begin(), points.end());
    map<int, vector<int>> xs, ys;
    for (int i = 0; i < k; i++) {
        auto& [p, q] = points[i];
        int pf = lower_bound(x.begin(), x.end(), p) - x.begin();
        int qf = lower_bound(y.begin(), y.end(), q) - y.begin();
        if (x[pf] == p && y[qf] == q) {
            res += i;
        } else if (x[pf] == p) {
            int r = y[qf];
            int l = y[qf - 1];
            res += sgt_y.get(1, 0, N, 0, l);
            res += sgt_y.get(1, 0, N, r, N);
            auto& v = xs[p];
            res += v.end() - upper_bound(v.begin(), v.end(), l);
        } else if (y[qf] == q) {
            int r = x[pf];
            int l = x[pf - 1];
            res += sgt_x.get(1, 0, N, 0, l);
            res += sgt_x.get(1, 0, N, r, N);
            auto& v = ys[q];
            res += v.end() - upper_bound(v.begin(), v.end(), l);
        }
        xs[p].emplace_back(q);
        ys[q].emplace_back(p);
        sgt_x.update(1, 0, N, p, 1);
        sgt_y.update(1, 0, N, q, 1);
    }
    long long ans = 1LL * k * (k - 1) / 2 - res;
    cout << ans << '\n';
    for (auto& [p, q] : points) {
        sgt_x.update(1, 0, N, p, -1);
        sgt_y.update(1, 0, N, q, -1);
    }
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