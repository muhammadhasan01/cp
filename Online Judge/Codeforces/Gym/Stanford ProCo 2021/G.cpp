#include <bits/stdc++.h>

using namespace std;

template<int N, typename T, T TERM>
struct SegtreeLazy {
    vector<T> t;
    vector<int> lazy;
    SegtreeLazy() {
        t.assign(4 * N, 0);
        lazy.assign(4 * N, 0);
    }

    T combine(const T& x, const T& y) {
        return (x > y ? x : y);
    }

    void build(int v, int s, int e, vector<T>& a) {
        lazy[v] = 0;
        if (s == e) {
            t[v] = a[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, a);
        build(v << 1 | 1, mid + 1, e, a);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    void push(int v, int s, int e) {
        if (lazy[v] == 0 || s == e) return;
        t[v << 1] += lazy[v];
        t[v << 1 | 1] += lazy[v];
        lazy[v << 1] += lazy[v];
        lazy[v << 1 | 1] += lazy[v];
        lazy[v] = 0;
    }

    void update(int v, int s, int e, int l, int r, T val) {
        if (l > r) return;
        if (l == s && e == r) {
            t[v] += val;
            lazy[v] += val;
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        update(v << 1, s, mid, l, min(r, mid), val);
        update(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    T get(int v, int s, int e, int l, int r) {
        if (l > r)
            return TERM;
        if (l <= s && e <= r)
            return t[v];
        push(v, s, e);
        int mid = (s + e) >> 1;
        T p1 = get(v << 1, s, mid, l, min(r, mid));
        T p2 = get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
        return combine(p1, p2);
    }
};

const int N = 1e5 + 5;
const int INF = 2e9;

int n, m, k;
int y[N];
pair<int, int> p[N];
SegtreeLazy<N, int, -INF> sgt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    k = min(k, n + 5);
    for (int i = 1; i <= m; i++) {
        cin >> p[i].first >> p[i].second;
        y[i] = p[i].second;
    }
    sort(p + 1, p + 1 + m);
    sort(y + 1, y + 1 + m);
    
    auto upd = [&](int val, int d) -> void {
        int l = lower_bound(y + 1, y + 1 + m, val) - y;
        int r = lower_bound(y + 1, y + 1 + m, val + k) - y - 1;
        sgt.update(1, 1, m, l, r, d);
    };

    int ans = 0;
    for (int i = 1, j = 1; i <= m; i++) {
        upd(p[i].second, 1);
        while (p[j].first <= p[i].first - k) {
            upd(p[j++].second, -1);
        }
        ans = max(ans, sgt.get(1, 1, m, 1, m));
    }
    cout << ans << '\n';

    return 0;
}