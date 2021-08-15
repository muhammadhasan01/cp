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
        return (x < y ? x : y);
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

const int INF = 2e9;
const int M = 1e6 + 5;
const int N = 3e5 + 5;
const int TERM = 0;

int n, m;
tuple<int, int, int> p[N];
SegtreeLazy<M, int, TERM> sgt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        auto& [w, l, r] = p[i];
        cin >> l >> r >> w;
    }
    sort(p + 1, p + 1 + n);
    int ans = INF;
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= n && sgt.get(1, 1, m - 1, 1, m - 1) == 0) {
            auto [_, l, r] = p[j++];
            sgt.update(1, 1, m - 1, l, r - 1, 1);
        }
        if (sgt.get(1, 1, m - 1, 1, m - 1) > 0) {
            ans = min(ans, get<0>(p[j - 1]) - get<0>(p[i]));
        }
        auto [_, l, r] = p[i];
        sgt.update(1, 1, m - 1, l, r - 1, -1);
    }
    cout << ans << '\n';

    return 0;
}