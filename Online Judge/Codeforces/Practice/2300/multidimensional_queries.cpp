#include <bits/stdc++.h>

using namespace std;

template<int MAXN, typename T, T TERM, T(*combine)(T, T)>
struct Segtree {
    vector<T> t;
    Segtree() {
        t.assign(4 * MAXN, TERM);
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

    void update(int v, int s, int e, int pos, T val) {
        if (s == e && s == pos) {
            t[v] = val;
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

const int INF = 2e9;
const int N = 2e5 + 5;
const int K = 6;
const int M = (1 << K);

int maks(int x, int y) {
    return (x > y ? x : y);
}

int n, k, q;
int a[N][K];
Segtree<N, int, -INF, maks> sgt_max[M];

void update_pos(int pos) {
    for (int mask = 0; mask < (1 << k); mask++) {
        int val = 0;
        for (int i = 0; i < k; i++) {
            bool b = mask & (1 << i);
            if (b) {
                val += a[pos][i + 1];
            } else {
                val -= a[pos][i + 1];
            }
        }
        sgt_max[mask].update(1, 1, n, pos, val);
    }
}

int get_answer(int l, int r) {
    int ret = -INF;
    int m = (1 << k) - 1;
    for (int mask = 0; mask < (1 << k); mask++) {
        int mx = sgt_max[mask].get(1, 1, n, l, r);
        int omask = m - mask;
        int mn = sgt_max[omask].get(1, 1, n, l, r);
        ret = max(ret, mx + mn);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> a[i][j];
        }
        update_pos(i);
    }
    cin >> q;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int i;
            cin >> i;
            for (int j = 1; j <= k; j++) {
                cin >> a[i][j];
            }
            update_pos(i);
        } else if (tp == 2) {
            int l, r;
            cin >> l >> r;
            cout << get_answer(l, r) << '\n';
        }
    }

    return 0;
}