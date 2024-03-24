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

const long long INF = 1e16;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> pre(n + 2);
    for (int i = 1; i <= n + 1; i++)  {
        pre[i] = a[i] + pre[i - 1];
    }

    auto can = [&](long long x) -> bool {
        SegmentTree<Info> sgt(n + 2);
        sgt.modify(0, 0LL);
        vector<long long> dp(n + 2);
        for (int i = 1; i <= n + 1; i++) {
            long long l = 1, r = i, at = -1;
            while (l <= r) {
                long long mid = (l + r) >> 1;
                if (pre[i - 1] - pre[mid - 1] <= x) {
                    r = mid - 1;
                    at = mid;
                } else {
                    l = mid + 1;
                }
            }
            dp[i] = sgt.rangeQuery(at - 1, i - 1).val + a[i];
            sgt.modify(i, dp[i]);
        }
        return dp[n + 1] <= x;
    };

    long long l = 0, r = INF, ans = -1;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
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