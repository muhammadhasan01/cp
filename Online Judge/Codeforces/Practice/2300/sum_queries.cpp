#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9 + 5;
const int K = 10;

struct node {
    int best;
    int mn[K];
    node() {
        best = INF;
        for (int i = 0; i < K; i++) {
            mn[i] = INF;
        }
    }

    int& operator[](int i) {
        return mn[i];
    }
};

template<int MAXN, typename T = node>
struct Segtree {
    vector<T> t;
    Segtree() {
        t.assign(4 * MAXN, node());
    }

    T combine(T x, T y) {
        T ret = node();
        ret.best = min(x.best, y.best);
        for (int i = 0; i < K; i++) {
            ret[i] = min(x[i], y[i]);
            if (x[i] == INF || y[i] == INF) {
                continue;
            }
            ret.best = min(ret.best, x[i] + y[i]);
        }
        return ret;
    }

    void update(int v, int s, int e, int pos, int val) {
        if (s == e && s == pos) {
            t[v] = node();
            int x = val;
            int i = 0;
            while (x > 0) {
                if (x % 10 > 0) {
                    t[v][i] = val;
                }
                i += 1;
                x /= 10;
            }
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
            return node();
        if (l <= s && e <= r)
            return t[v];
        int mid = (s + e) >> 1;
        T p1 = get(v << 1, s, mid, l, r);
        T p2 = get(v << 1 | 1, mid + 1, e, l, r);
        return combine(p1, p2);
    }
};

const int N = 2e5 + 5;

Segtree<N> sgt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    auto update_val = [&](int i, int val) -> void {
        sgt.update(1, 1, n, i, val);
    };
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        update_val(i, val);
    }
    auto get = [&](int l, int r) -> int {
        if (l == r) {
            return -1;
        }
        node ret = sgt.get(1, 1, n, l, r);
        if (ret.best == INF) {
            ret.best = -1;
        }
        return ret.best; 
    };
    while (m--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int i, val;
            cin >> i >> val;
            update_val(i, val);
        } else if (tp == 2) {
            int l, r;
            cin >> l >> r;
            cout << get(l, r) << '\n';
        }
    }
    
    return 0;
}