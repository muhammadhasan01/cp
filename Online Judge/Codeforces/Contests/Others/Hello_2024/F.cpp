#include <bits/stdc++.h>

using namespace std;

template<int MAXN, typename T, const T TERM>
struct SegtreeLazy {
    vector<T> t;
    vector<T> lazy;
    SegtreeLazy() {
        t.assign(4 * MAXN, 0);
        lazy.assign(4 * MAXN, 0);
    }

    T combine(const T& x, const T& y) {
        return (x > y ? x : y);
    }

    void upd(T& cur, T val) {
        cur += val;
    }

    void push(int v, int s, int e) {
        if (lazy[v] == 0 || s == e) return;
        upd(t[v << 1], lazy[v]);
        upd(t[v << 1 | 1], lazy[v]);
        upd(lazy[v << 1], lazy[v]);
        upd(lazy[v << 1 | 1], lazy[v]);
        lazy[v] = 0;
    }

    void update(int v, int s, int e, int l, int r, T val) {
        if (l > r) return;
        if (l == s && e == r) {
            upd(t[v], val);
            upd(lazy[v], val);
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

const int N = 6e5 + 5;
const long long INF = 2e18;

SegtreeLazy<N, long long, -INF> sgt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    long long S = 0;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        S += a[i];
    }
    vector<long long> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i < n; i++) {
        long long c;
        cin >> c;
    }
    for (int i = 1; i <= n; i++) {
        long long cur = a[i] - b[i];
        sgt.update(1, 1, n, 1, i, cur);
    }
    while (q--) {
        int p;
        long long x, y, z;
        cin >> p >> x >> y >> z;
        S -= a[p];
        sgt.update(1, 1, n, 1, p, -(a[p] - b[p]));
        a[p] = x;
        b[p] = y;
        sgt.update(1, 1, n, 1, p, a[p] - b[p]);
        S += a[p];
        cout << S - max(0LL, sgt.get(1, 1, n, 1, n)) << '\n';
    }
    
    return 0;
}