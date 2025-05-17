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
    long long submax;
    long long premax;
    long long sufmax;
    long long sum;
    Info() {
        submax = 0LL;
        premax = 0LL;
        sufmax = 0LL;
        sum = 0LL;
    }
    Info(long long v) {
        submax = v;
        premax = v;
        sufmax = v;
        sum = v;
    }
};

Info operator+(const Info& lhs, const Info& rhs) {
    Info ret;
    ret.submax = max({lhs.submax, rhs.submax, lhs.sufmax + rhs.premax});
    ret.premax = max(lhs.premax, lhs.sum + rhs.premax);
    ret.sufmax = max(lhs.sufmax + rhs.sum, rhs.sufmax);
    ret.sum = lhs.sum + rhs.sum;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<Info> init(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        init[i] = Info(x);
    }
    SegmentTree<Info> sgt(init);
    while (m--) {
        int k, x;
        cin >> k >> x;
        k--;
        sgt.modify(k, x);
        cout << max(0LL, sgt.rangeQuery(0, n - 1).submax) << '\n'; 
    }
    
    return 0;
}