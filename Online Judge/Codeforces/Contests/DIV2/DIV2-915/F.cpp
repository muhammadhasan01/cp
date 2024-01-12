#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

struct SegmentTreeLazy {
    int n;
    vector<pii> t;
    vector<int> lazy;
    SegmentTreeLazy(int t_n) : n(t_n), t(4 << __lg(t_n)), lazy(4 << __lg(t_n)) {
        function<void(int, int, int)> build = [&](int v, int s, int e) {
            if (s == e) {
                t[v] = {0, 1};
                return;
            }
            int mid = (s + e) >> 1;
            build(v << 1, s, mid);
            build(v << 1 | 1, mid + 1, e);
            t[v] = combine(t[v << 1], t[v << 1 | 1]);
        };
        build(1, 0, n - 1);
    }

    pii combine(const pii& x, const pii& y) {
        if (x.first == y.first) {
            return {x.first, x.second + y.second};
        }
        return min(x, y);
    }

    void push(int v, int s, int e) {
        if (lazy[v] == 0 || s == e) {
            return;
        }
        t[v << 1].first += lazy[v];
        t[v << 1 | 1].first += lazy[v];
        lazy[v << 1] += lazy[v];
        lazy[v << 1 | 1] += lazy[v];
        lazy[v] = 0;
    }

    void update(int v, int s, int e, int l, int r, int val) {
        if (l > r) {
            return;
        }
        if (l == s && e == r) {
            t[v].first += val;
            lazy[v] += val;
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        update(v << 1, s, mid, l, min(r, mid), val);
        update(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    pii get(int v, int s, int e, int l, int r) {
        if (l > r) {
            return {INT_MAX, 0};
        }
        if (l <= s && e <= r) {
            return t[v];
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        pii p1 = get(v << 1, s, mid, l, min(r, mid));
        pii p2 = get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
        return combine(p1, p2);
    }

    void update(int l, int r, int val) {
        update(1, 0, n - 1, l, r, val);
    }

    pii get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (is_sorted(a.begin() + 1, a.end())) {
        cout << n - 2 << '\n';
        return;
    }
    vector<pii> candidates;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        p[a[i]] = i;
    }
    for (int x = 1; x <= n; x++) {
        if (x != p[x]) {
            candidates.emplace_back(x, p[x]);
        }
    }
    vector<pii> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = {a[i], i};
        if (i > 0) {
            pre[i] = max(pre[i], pre[i - 1]);
        }
    }
    vector<pii> suf(n + 1);
    for (int i = n; i >= 1; i--) {
        suf[i] = {a[i], i};
        if (i + 1 <= n) {
            suf[i] = min(suf[i], suf[i + 1]);
        }
    }
    for (int i = 2; i < n; i++) {
        candidates.emplace_back(pre[i - 1].second, suf[i + 1].second);
    }
    SegmentTreeLazy sgt(n + 1);

    auto updatePosition = [&](int i, int val) -> void {
        sgt.update(min(i, a[i]), max(i, a[i]), val);
    };

    auto swapPosition = [&](int i, int j) -> void {
        updatePosition(i, -1);
        updatePosition(j, -1);
        swap(a[i], a[j]);
        updatePosition(i, 1);
        updatePosition(j, 1);
    };

    auto getAnswer = [&]() -> int {
        auto [val, cnt] = sgt.get(1, n);
        if (val == 1) {
            return cnt;
        }
        return 0;
    };

    for (int i = 1; i <= n; i++) {
        updatePosition(i, 1);
    }
    sort(candidates.begin(), candidates.end());
    candidates.resize(unique(candidates.begin(), candidates.end()) - candidates.begin());
    int ans = 0;
    for (auto [i, j] : candidates) {
        swapPosition(i, j);
        ans = max(ans, getAnswer());
        swapPosition(i, j);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}