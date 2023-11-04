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
    Info() : val(0) {}
    Info(long long v) : val(v) {}
};

Info operator+(const Info& lhs, const Info& rhs) {
    return Info(lhs.val + rhs.val);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    vector<pair<int, int>> basket(m + 1);
    for (int i = 1; i <= m; i++) {
        auto& [b, a] = basket[i];
        cin >> b >> a;
    }
    vector<vector<tuple<int, int, int>>> query(m + 1);
    for (int i = 1; i <= q; i++) {
        int d, l, r;
        cin >> d >> l >> r;
        query[d].emplace_back(l, r, i);
    }
    SegmentTree<Info> SegmentTree(n + 1);
    vector<int> val(n + 1);
    vector<long long> ans(q + 1);
    for (int i = 1; i <= m; i++) {
        auto& [b, a] = basket[i];
        val[b] = min(c[b], val[b] + a);
        SegmentTree.modify(b, Info(val[b]));
        for (auto [l, r, pos] : query[i]) {
            ans[pos] = SegmentTree.rangeQuery(l, r).val;
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    } 

    return 0;
}