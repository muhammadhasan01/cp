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
    pair<int, int> val;
    Info() : val({-INT_MAX, -1}) {}
    Info(pair<int, int> v) : val(v) {}
};

Info operator+(const Info& lhs, const Info& rhs) {
    return Info(max(lhs.val, rhs.val));
}

template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    
    BIT(int t_n) : n(t_n), bit(t_n + 1, -INT_MAX) {}

    void add(int x, T val) {
        for ( ; x <= n; x += x & -x)
            bit[x] = max(bit[x], val);
    }

    T get(int x) {
        T ret = -INT_MAX;
        for ( ; x > 0; x -= x & -x)
            ret = max(ret, bit[x]);
        return ret;
    }

    T query(int l, int r) {
        return get(r) - get(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }
    vector<int> ord(n + 1);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int& i, int& j) {
        if (pref[i] == pref[j]) {
            return i < j;
        }
        return pref[i] < pref[j];
    });
    vector<Info> init(n + 1);
    for (int i = 0; i <= n; i++) {
        init[i] = {-INT_MAX, i};
    }
    SegmentTree<Info> segtree(init);
    BIT<int> bit(n + 1);
    for (int i : ord) {
        auto [res, j] = segtree.rangeQuery(0, i - 1).val;
        if (res != -INT_MAX) {
            int cur = res - i + 1;
        }
        segtree.modify(i, bit.get(i - 1) + i);
    }

    
    return 0;
}