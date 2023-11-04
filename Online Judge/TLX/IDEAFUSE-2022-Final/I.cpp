#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e4 + 5;
const int TERM = 0;

struct SegtreeLazy {
    vector<int> t;
    vector<int> lazy;
    SegtreeLazy() {
        t.assign(4 * MAXN, TERM);
        lazy.assign(4 * MAXN, 0);
    }

    int combine(const int& x, const int& y) {
        return x + y;
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

    // val = 1 -> flip
    // val = 2 -> turn to zero
    // val = 3 -> turn to one
    void upd(int& cur, int len, int val) {
        if (val == 1) {
            cur = len - cur;
        } else if (val == 2) {
            cur = 0;
        } else if (val == 3) {
            cur = len;
        }
    }

    void updLazy(int& cur, int val) {
        if (val == 1) {
            cur = (cur < 2 ? 1 - cur : (cur == 2 ? 3 : 2));
        } else if (val == 2) {
            cur = 2;
        } else if (val == 3) {
            cur = 3;
        }
    }

    void push(int v, int s, int e) {
        if (lazy[v] == 0 || s == e) return;
        int mid = (s + e) >> 1;
        upd(t[v << 1], mid - s + 1, lazy[v]);
        upd(t[v << 1 | 1], e - mid, lazy[v]);
        updLazy(lazy[v << 1], lazy[v]);
        updLazy(lazy[v << 1 | 1], lazy[v]);
        lazy[v] = 0;
    }

    void update(int v, int s, int e, int l, int r, int val) {
        if (l > r) return;
        if (l == s && e == r) {
            upd(t[v], e - s + 1, val);
            updLazy(lazy[v], val);
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
            return TERM;
        if (l <= s && e <= r)
            return t[v];
        push(v, s, e);
        int mid = (s + e) >> 1;
        int p1 = get(v << 1, s, mid, l, min(r, mid));
        int p2 = get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
        return combine(p1, p2);
    }
} sgt;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sgt.build(1, 0, n - 1, a);
    while (q--) {
        string s;
        int l, r;
        cin >> s >> l >> r;
        l--, r--;
        if (s[0] == 'f') {
            sgt.update(1, 0, n - 1, l, r, 1);
        } else if (s[0] == 's') {
            int one = sgt.get(1, 0, n - 1, l, r);
            sgt.update(1, 0, n - 1, l, r - one, 2);
            sgt.update(1, 0, n - 1, r - one + 1, r, 3);
        }
    }
    long long ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int one = sgt.get(1, 0, n - 1, i, i);
        if (one > 0) {
            cnt++;
        } else {
            ans += cnt;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}