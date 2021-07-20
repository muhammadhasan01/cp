#include <bits/stdc++.h>

using namespace std;

template<int MAXN, typename T, const T& TERM>
struct SegtreeLazy {
    vector<T> t;
    vector<int> lazy;
    SegtreeLazy() {
        t.assign(4 * MAXN, TERM);
        lazy.assign(4 * MAXN, 0);
    }

    T combine(const T& x, const T& y) {
        return x + y;
    }

    void build(int v, int s, int e) {
        lazy[v] = 0;
        if (s == e) {
            t[v] = (s > 0);
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    void push(int v, int s, int e) {
        if (lazy[v] == 0 || s == e) return;
        if (lazy[v]) {
            t[v << 1] *= -1;
            t[v << 1 | 1] *= -1;
        }
        lazy[v << 1] ^= lazy[v];
        lazy[v << 1 | 1] ^= lazy[v];
        lazy[v] = 0;
    }

    void update(int v, int s, int e, int l, int r) {
        if (l > r) return;
        if (l == s && e == r) {
            t[v] *= -1;
            lazy[v] ^= 1;
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        update(v << 1, s, mid, l, min(r, mid));
        update(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
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
const int TERM = 0;

SegtreeLazy<N, int, TERM> sgt;

void solve() {
    sgt.build(1, 0, N - 1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << sgt.get(1, 0, N - 1, 0, x) << '\n';
        sgt.update(1, 0, N - 1, x + 1, N - 1);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("reflection.in", "r", stdin);
    
    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}