#include <bits/stdc++.h>

using namespace std;

template<class Info, class Merge = plus<Info>>
struct SegmentTree {
    const int n;
    const Merge merge;
    vector<Info> t;
    SegmentTree(int len) : n(len), merge(Merge()), t(4 << __lg(len)) {}
    SegmentTree(vector<Info> init) : SegmentTree(init.size()) {
        function<void(int, int, int)> build = [&](int v, int s, int e) {
            if (s == e) {
                t[v] = init[s];
                return;
            }
            int mid = (s + e) >> 1;
            build(v << 1, s, mid);
            build(v << 1 | 1, mid + 1, e);
            pull(v);
        };
        build(1, 0, n - 1);
    }

    void pull(int v) {
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }

    void modify(int v, int s, int e, int pos, const Info &val) {
        if (s == e && s == pos) {
            t[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid) {
            modify(v << 1, s, mid, pos, val);
        } else {
            modify(v << 1 | 1, mid + 1, e, pos, val);
        }
        pull(v);
    }

    void modify(int p, const Info &v) {
        modify(1, 0, n - 1, p, v);
    }

    Info rangeQuery(int v, int s, int e, int l, int r) {
        if (e < l || s > r || l > r) {
            return Info();
        }
        if (l <= s && e <= r) {
            return t[v];
        }
        int mid = (s + e) >> 1;
        return merge(rangeQuery(v << 1, s, mid, l, r), rangeQuery(v << 1 | 1, mid + 1, e, l, r));
    }

    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n - 1, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<long long> values(n + 1);
    set<int> st;
    {
        vector<int> pos(m);
        for (int i = 0; i < m; i++) {
            cin >> pos[i];
            st.emplace(pos[i]);
        }
        for (int i = 0; i < m; i++) {
            cin >> values[pos[i]];
        }
    }

    auto F = [&](long long x) -> long long {
        return 1LL * x * (x + 1) / 2;
    };

    vector<long long> dp(n + 1);
    SegmentTree<long long> sgt(n + 1);
    for (int i = 1; i < n; i++) {
        if (values[i] == 0) {
            continue;
        }
        int j = *st.upper_bound(i);
        dp[i] = values[i] * F(j - i - 1);
        sgt.modify(i, dp[i]);
    }

    auto handleUpdate = [&](int x) -> void {
        st.emplace(x);
        int l = *prev(st.lower_bound(x));
        int r = *st.upper_bound(x);
        dp[l] = values[l] * F(x - l - 1);
        sgt.modify(l, dp[l]);
        dp[x] = values[x] * F(r - x - 1);
        sgt.modify(x, dp[x]);
    };

    auto handleQuery = [&](int l, int r) -> long long {
        int lft = *prev(st.upper_bound(l));
        int rgt = *prev(st.upper_bound(r));
        long long ret = sgt.rangeQuery(lft, rgt);
        if (lft < l) {
            int r2 = *st.lower_bound(l);
            int len = r2 - lft - 1;
            int len2 = r2 - l;
            ret -= values[lft] * (F(len) - F(len2));
        }
        if (rgt < r) {
            int r2 = *st.lower_bound(r);
            int len2 = r2 - r - 1;
            ret -= values[rgt] * F(len2);
        } else if (rgt == r) {
            ret -= dp[rgt];
        }
        return ret;
    };

    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x;
            cin >> x;
            cin >> values[x];
            handleUpdate(x);
        } else if (tp == 2) {
            int l, r;
            cin >> l >> r;
            cout << handleQuery(l, r) << '\n';
        }
    }
    
    return 0;
}