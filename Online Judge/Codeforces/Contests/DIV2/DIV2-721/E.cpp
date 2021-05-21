#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int N = 35005;

struct SegtreeLazy {
    vector<int> t;
    vector<int> lazy;
    SegtreeLazy() {
        t.assign(4 * N, INF);
        lazy.assign(4 * N, 0);
    }

    int combine(const int& x, const int& y) {
        return (x < y ? x : y);
    }

    void build(int v, int s, int e, vector<int>& a) {
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

    void update(int v, int s, int e, int l, int r, int val) {
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

    int get(int v, int s, int e, int l, int r) {
        if (l > r)
            return INF;
        if (l <= s && e <= r)
            return t[v];
        push(v, s, e);
        int mid = (s + e) >> 1;
        int p1 = get(v << 1, s, mid, l, min(r, mid));
        int p2 = get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
        return combine(p1, p2);
    }
} segtree;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> pre(n + 1), last(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pre[i] = last[a[i]];
        last[a[i]] = i;
    }
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int rep = 1; rep <= k; rep++) {
        segtree.build(1, 0, n, dp);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (pre[i] > 0) {
                segtree.update(1, 0, n, 0, pre[i] - 1, i - pre[i]);
            }
            dp[i] = segtree.get(1, 0, n, 0, i);
        }
    }
    cout << dp[n] << '\n';

    return 0;
}