#include <bits/stdc++.h>

using namespace std;

template<int MAXN, typename T, const T& TERM>
struct SegtreeLazy {
    vector<T> t;
    vector<T> lazy;
    SegtreeLazy() {
        t.assign(4 * MAXN, TERM);
        lazy.assign(4 * MAXN, TERM);
    }

    T combine(const T& x, const T& y) {
        return x + y;
    }

    void build(int v, int s, int e, vector<T>& a) {
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
        int mid = (s + e) >> 1;
        t[v << 1] += 1LL * (mid - s + 1) * lazy[v];
        t[v << 1 | 1] += 1LL * (e - mid) * lazy[v];
        lazy[v << 1] += lazy[v];
        lazy[v << 1 | 1] += lazy[v];
        lazy[v] = 0;
    }

    void update(int v, int s, int e, int l, int r, T val) {
        if (l > r) return;
        if (l == s && e == r) {
            t[v] += 1LL * (e - s + 1) * val;
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

const int N = 2e5 + 5;
const long long TERM = 0;

SegtreeLazy<N, long long, TERM> sgt_dp;
SegtreeLazy<N, long long, TERM> sgt_cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 2, -1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> dp(n + 2);
    sgt_cnt.build(1, 1, n, dp);
    set<int> bounds = {0, n};
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        if (i > 1 && a[i] != a[i - 1]) {
            dp[i] += dp[i - 1];
        }
        if (i + 1 <= n && a[i] == a[i + 1]) {
            bounds.emplace(i);
        }
    }
    sgt_dp.build(1, 1, n, dp);
    auto get_value = [&](int i) {
        int cur = sgt_cnt.get(1, 1, n, i, i) % 2;
        if (cur) {
            return 1 - a[i];
        }
        return a[i];
    };
    auto update_query = [&](int l, int r) {
        // update the counts from [l ... r]
        sgt_cnt.update(1, 1, n, l, r, 1);
        // update for a[l] first
        if (l > 1) {
            int val = get_value(l);
            int val_b = get_value(l - 1);
            long long dp_b = sgt_dp.get(1, 1, n, l - 1, l - 1);
            long long new_dp = (val == val_b ? 1LL : dp_b + 1);
            long long cur_dp = sgt_dp.get(1, 1, n, l, l);
            sgt_dp.update(1, 1, n, l, l, new_dp - cur_dp);
            if (val_b == val) {
                bounds.emplace(l - 1);
            } else {
                bounds.erase(l - 1);
            }
        }
        // update for [l + 1 ... r]
        if (l < r) {
            int val = get_value(l + 1);
            int val_b = get_value(l);
            if (val != val_b) {
                int rgt = min(r, *bounds.upper_bound(l));
                long long new_dp = sgt_dp.get(1, 1, n, l, l) + 1;
                long long cur_dp = sgt_dp.get(1, 1, n, l + 1, l + 1);
                sgt_dp.update(1, 1, n, l + 1, rgt, new_dp - cur_dp);
            }
        }
        // update for a[r + 1]....
        if (r < n) {
            int val = get_value(r + 1);
            int val_b = get_value(r);
            long long dp_b = sgt_dp.get(1, 1, n, r, r);
            long long new_dp = (val == val_b ? 1LL : dp_b + 1);
            long long cur_dp = sgt_dp.get(1, 1, n, r + 1, r + 1);
            int rgt = *bounds.upper_bound(r);
            sgt_dp.update(1, 1, n, r + 1, rgt, new_dp - cur_dp);
            if (val_b == val) {
                bounds.emplace(r);
            } else {
                bounds.erase(r);
            }
        }
    };
    auto get_query = [&](int l, int r) {
        int lft = *(--bounds.lower_bound(l)) + 1;
        int rgt = min(r, *bounds.lower_bound(l));
        long long sub = 1LL * (rgt - l + 1) * (l - lft);
        return sgt_dp.get(1, 1, n, l, r) - sub;
    };
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int l, r;
            cin >> l >> r;
            update_query(l, r);
        } else if (tp == 2) {
            int l, r;
            cin >> l >> r;
            cout << get_query(l, r) << '\n';
        }
    }
    
    return 0;
}