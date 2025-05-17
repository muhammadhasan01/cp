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
    int val;
    int operation;
    Info() : val(0), operation(2) {}
    Info(int v) : val(v), operation(0) {}
    Info(int v, int op) : val(v), operation(op) {}
};

Info operator+(const Info& lhs, const Info& rhs) {
    if (lhs.operation == 2) {
        return rhs;
    }
    if (rhs.operation == 2) {
        return lhs;
    }
    assert(lhs.operation == rhs.operation);
    int op = lhs.operation;
    int val = op == 0 ? (lhs.val | rhs.val) : (lhs.val ^ rhs.val);
    return Info(val, op ^ 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int len = (1 << n);
    vector<Info> a(len);
    for (int i = 0; i < len; i++) {
        int x;
        cin >> x;
        a[i] = Info(x);
    }
    SegmentTree<Info> sgt(a);
    while (m--) {
        int p, b;
        cin >> p >> b;
        p--;
        sgt.modify(p, Info(b));
        Info res = sgt.rangeQuery(0, len - 1);
        cout << res.val << '\n';
    }
    
    return 0;
}