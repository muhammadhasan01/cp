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
    int a, b, c;
    Info() : a(0), b(0), c(0) {}
    Info(int t_a, int t_b, int t_c) : a(t_a), b(t_b), c(t_c) {}
};

Info operator+(const Info& lhs, const Info& rhs) {
    int mini = min(lhs.b, rhs.c);
    int a = lhs.a + rhs.a + mini;
    int b = lhs.b + rhs.b - mini;
    int c = lhs.c + rhs.c - mini;
    return Info(a, b, c);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<char> s(n + 1);
    vector<Info> info(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        if (s[i] == '(') {
            info[i] = Info(0, 1, 0);
        } else if (s[i] == ')') {
            info[i] = Info(0, 0, 1);
        }
    }
    SegmentTree<Info> segtree(info);
    while (q--) {
        int tp;
        cin >> tp;
        int l, r;
        cin >> l >> r;
        if (tp == 1) {
            if (s[l] == s[r]) {
                continue;
            }
            Info L = (s[l] == '(' ? Info(0, 1, 0) : Info(0, 0, 1));
            Info R = (s[r] == '(' ? Info(0, 1, 0) : Info(0, 0, 1));
            segtree.modify(l, R);
            segtree.modify(r, L);
            swap(s[l], s[r]);
        } else if (tp == 2) {
            int res = segtree.rangeQuery(l, r).a;
            cout << (2 * res == r - l + 1  ? "Yes" : "No") << '\n';
        }
    }
    
    return 0;
}