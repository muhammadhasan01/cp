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
    Info() : val(0) {}
    Info(int v) : val(v) {}
};

Info operator+(const Info& lhs, const Info& rhs) {
    return Info(max(lhs.val, rhs.val));
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<set<int>> st(n + 1, {-1, n});
    for (int i = 0; i < n; i++) {
        st[a[i]].emplace(i);
    }
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < n; i++) {
        pos[b[i]].emplace_back(i);
    }
    SegmentTree<Info> segtree(vector<Info>(a.begin(), a.end()));
    set<int> S = {-1, n + 1};
    for (int x = 1; x <= n; x++) {
        if (pos[x].empty()) {
            continue;
        }
        for (int i : pos[x]) {
            if (a[i] == b[i]) {
                continue;
            }
            int ls = *prev(S.lower_bound(i));
            int rs = *S.upper_bound(i);
            int lx = *prev(st[x].lower_bound(i));
            int rx = *st[x].upper_bound(i);
            if (ls < lx && segtree.rangeQuery(lx, i).val == x) {
                continue;
            }
            if (rs > rx && segtree.rangeQuery(i, rx).val == x) {
                continue;
            }
            cout << "NO" << '\n';
            return;
        }
        for (int i : pos[x]) {
            S.emplace(i);
        }
    }
    cout << "YES" << '\n';
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