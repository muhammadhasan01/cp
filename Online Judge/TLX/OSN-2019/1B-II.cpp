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

struct Info {
    long long val;
    Info() : val(LLONG_MAX) {}
    Info(long long v) : val(v) {}
};

Info operator+(const Info& lhs, const Info& rhs) {
    return Info(min(lhs.val, rhs.val));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int, int>>> ranges(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, p;
        cin >> a >> b >> p;
        ranges[b].emplace_back(a, p);
    }
    SegmentTree<Info> sgt(n + 1);
    vector<long long> dp(n + 1);
    dp[0] = 0LL;
    sgt.modify(0, Info(dp[0]));
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + s;
        for (auto [j, p] : ranges[i]) {
            dp[i] = min(dp[i], sgt.rangeQuery(j - 1, i - 1).val + p);
        }
        sgt.modify(i, dp[i]);
    }
    cout << dp[n] << '\n';
    
    return 0;
}