#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
const pair<int, int> TERM = make_pair(0, 0);

struct SegtreeLazy {
    vector<pair<int, int>> t;
    vector<pair<int, int>> lazy;
    SegtreeLazy() {
        t.assign(4 * MAXN, TERM);
        lazy.assign(4 * MAXN, TERM);
    }

    pair<int, int> combine(const pair<int, int>& x, const pair<int, int>& y) {
        auto [x1, y1] = x;
        auto [x2, y2] = y;
        return make_pair(max(x1, x2), max(y1, y2));
    }

    void build(int v, int s, int e, vector<pair<int, int>>& a) {
        if (s == e) {
            t[v] = a[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, a);
        build(v << 1 | 1, mid + 1, e, a);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    void update(pair<int, int>& cur, pair<int, int> val) {
        cur.first ^= val.first;
        cur.second = val.second;
    }

    void push(int v, int s, int e) {
        if (lazy[v] == TERM || s == e) return;
        update(t[v << 1], lazy[v]);
        update(t[v << 1 | 1], lazy[v]);
        update(lazy[v << 1], lazy[v]);
        update(lazy[v << 1 | 1], lazy[v]);
        lazy[v] = TERM;
    }

    void update(int v, int s, int e, int l, int r, pair<int, int> val) {
        if (l > r) return;
        if (l == s && e == r) {
            update(t[v], val);
            update(lazy[v], val);
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        update(v << 1, s, mid, l, min(r, mid), val);
        update(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    pair<int, int> get(int v, int s, int e, int l, int r) {
        if (l > r)
            return TERM;
        if (l <= s && e <= r)
            return t[v];
        push(v, s, e);
        int mid = (s + e) >> 1;
        pair<int, int> p1 = get(v << 1, s, mid, l, min(r, mid));
        pair<int, int> p2 = get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
        return combine(p1, p2);
    }
} sgt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<pair<int, int>> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = make_pair(min(1, a[i]), 0);
    }
    sgt.build(1, 1, n, b);
    vector<tuple<int, int, int>> qr(q + 1);
    for (int i = 1; i <= q; i++) {
        auto& [l, r, x] = qr[i];
        cin >> l >> r >> x;
        sgt.update(1, 1, n, l, r, make_pair(1, i));
    }
    for (int i = 1; i <= n; i++) {
        auto [x, y] = sgt.get(1, 1, n, i, i);
        if (x == 1) {
            if (y == 0) {
                cout << a[i];
            } else {
                cout << get<2>(qr[y]);
            }
        } else {
            cout << 0;
        }
        cout << " \n"[i == n];
    }

    return 0;
}