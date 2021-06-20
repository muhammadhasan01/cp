#include <bits/stdc++.h>

using namespace std;
using pli = pair<long long, int>;

template<int MAXN, class T, const T& TERM>
struct Segtree {
    vector<T> t;
    Segtree() {
        t.assign(4 * MAXN, TERM);
    }

    T combine(const T& x, const T& y) {
        return (x > y ? x : y);
    }

    void build(int v, int s, int e, vector<T>& a) {
        if (s == e) {
            t[v] = a[s];
        } else {
            int mid = (s + e) >> 1;
            build(v << 1, s, mid, a);
            build(v << 1 | 1, mid + 1, e, a);
            t[v] = combine(t[v << 1], t[v << 1 | 1]);
        }
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

const long long INF = 1e18;
const pli TERM = {-INF, 0};
const int N = 2e5 + 5;

int n, q;
long long d[N];
long long h[N];
long long dist[N];
Segtree<N, pli, TERM> lft, rgt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        d[n + i] = d[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        h[n + i] = h[i];
    }
    int m = 2 * n;
    vector<pli> pre(m + 1);
    for (int i = 1; i <= m; i++) {
        dist[i] = dist[i - 1] + d[i - 1];
        pre[i] = make_pair(dist[i] + h[i] * 2, i);
    }
    vector<pli> suf(m + 1);
    long long cur_dist = 0;
    for (int i = m; i >= 1; i--) {
        suf[i] = make_pair(cur_dist + h[i] * 2, i);
        cur_dist += d[i - 1];
    }
    lft.build(1, 1, m, suf);
    rgt.build(1, 1, m, pre);
    auto get_distance = [&](int u, int v) -> long long {
        if (u > v) swap(u, v);
        return (h[u] + h[v]) * 2 + dist[v] - dist[u];
    };
    auto get_furthest = [&](int u, int l, int r) -> int {
        auto [dist_x, x] = lft.get(1, 1, m, l, u - 1);
        auto [dist_y, y] = rgt.get(1, 1, m, u + 1, r);
        int ret;
        if (x == 0) {
            ret = y;
        } else if (y == 0) {
            ret = x;
        } else if (get_distance(u, x) > get_distance(u, y)) {
            ret = x;
        } else {
            ret = y;
        }
        return ret;
    };
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a > b) b += n;
        int x = b + 1, y = a - 1 + n;
        int u = get_furthest(x, x, y);
        int v = get_furthest(u, x, y);
        long long ans = get_distance(u, v);
        cout << ans << '\n';
    }

    return 0;
}