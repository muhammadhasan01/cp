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
            t[v] = merge(t[v], val);
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
 
const long long INF = 1e18 + 5;
 
struct Info {
    pair<long long, long long> val;
    Info() : val({-INF, INF}) {}
    Info(pair<long long, long long> v) : val(v) {}
};
 
Info operator+(const Info& lhs, const Info& rhs) {
    return Info({max(lhs.val.first, rhs.val.first), min(lhs.val.second, rhs.val.second)});
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> pre(n + 2);
    for (int i = 1; i <= n + 1; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    vector<Info> init(n + 2);
    for (int i = 0; i <= n + 1; i++) {
        init[i] = Info({pre[i], pre[i]});
    }
    SegmentTree<Info> segtree(init);
    vector<pair<long long, int>> p(n);
    for (int i = 1; i <= n; i++) {
        p[i - 1] = make_pair(a[i], i);
    }
    sort(p.rbegin(), p.rend());
    set<int> st = {0, n + 1};
    stack<int> pos;
    for (auto [val, idx] : p) {
        while (!pos.empty() && a[pos.top()] > val) {
            st.emplace(pos.top());
            pos.pop();
        }
        int L = *prev(st.lower_bound(idx)) + 1;
        int R = *st.upper_bound(idx) - 1;
        long long maxLeft = pre[idx] - segtree.rangeQuery(L - 1, idx - 1).val.second;
        long long maxRight = segtree.rangeQuery(idx, R).val.first - pre[idx - 1];
        long long sum = maxLeft + maxRight - a[idx];
        if (sum > val) {
            cout << "NO" << '\n';
            return;
        }
        pos.emplace(idx);
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