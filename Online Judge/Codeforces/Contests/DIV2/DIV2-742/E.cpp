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

const int N = 2e5 + 5;
const long long TERM = 0;

SegtreeLazy<N, long long, TERM> sgt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> dp(n + 1, 1);
    set<int> st;
    st.emplace(n + 1);
    for (int i = 2; i <= n; i++) {
        if (a[i] >= a[i - 1]) {
            dp[i] = 1 + dp[i - 1];
        } else {
            st.emplace(i);
        }
    }
    auto handle = [&](int i) -> void {
        if (i == 1) {
            return;
        }
        int j = i - 1;
        if (a[j] <= a[i]) {
            st.erase(i);
        } else {
            st.emplace(i);
        }
    };
    sgt.build(1, 1, n, dp);
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int pos, y;
            cin >> pos >> y;
            int x = a[pos];
            a[pos] = x;
            handle(pos);
            if (pos + 1 <= n) {
                handle(pos + 1);
            }
            long long cur = sgt.get(1, 1, n, pos, pos);
            long long dif = 0;
            if (pos > 1) {
                bool bfr = (a[pos - 1] <= x);
                bool aft = (a[pos - 1] <= y);
                if (bfr != aft) {
                    if (bfr) {
                        dif = 1 - cur;
                        sgt.update(1, 1, n, pos, pos, dif);
                    } else {
                        int prev = sgt.get(1, 1, n, pos - 1, pos - 1);
                        dif = prev;
                        sgt.update(1, 1, n, pos, pos, dif);
                    }
                }
            }
            if (pos < n) {
                bool bfr = (x <= a[pos + 1]);
                bool aft = (y <= a[pos + 1]);
                if (bfr != aft) {
                    if (bfr) {
                        dif = -cur;
                        int r = *st.upper_bound(pos + 1);
                        sgt.update(1, 1, n, pos + 1, r, dif);
                    } else {
                        long long now = cur + dif;
                        dif = now;
                        int r = *st.upper_bound(pos + 1);
                        sgt.update(1, 1, n, pos + 1, r, dif);
                    }
                } else {
                    int l = i + 1;
                    int r = *st.upper_bound(i) - 1;
                    sgt.update(1, 1, n, l, r, dif);
                }
            }
        } else if (tp == 2) {
            int l, r;
            cin >> l >> r;
            int rgt = min(r, *st.upper_bound(l));
            
        }
    }
    
    return 0;
}