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
            t[v] += val;
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

template<typename T>
struct Compresser {
    vector<T> nums;
    
    Compresser() { }

    Compresser(vector<T>& v) {
        nums.assign(v.begin(), v.end());
        finish();
    }
 
    void add(T x) {
        nums.emplace_back(x);
    }
 
    void finish() {
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    }
 
    int getId(T x) {
        return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
    }

    T getValue(int id) {
        return nums[id - 1];
    }
 
    int getLen() {
        return nums.size();
    }
};

const int K = 2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, p;
    cin >> n >> p;
    Compresser<int> comp;
    vector<vector<int>> vals(K + 1);
    for (int i = 0; i < p; i++) {
        int t, w;
        cin >> t >> w;
        vals[t].emplace_back(w);
        for (int dif = -1; dif <= 1; dif++) {
            comp.add(w + dif);
        }
    }
    int q;
    cin >> q;
    vector<pair<int, int>> points(q);
    for (auto& [x, y] : points) {
        cin >> x >> y;
        for (int dif = -1; dif <= 1; dif++) {
            comp.add(y + dif);
        }
    }
    comp.finish();
    vector<int> ans(q);
    int len = comp.getLen();
    // left
    {
        vector<tuple<int, int, int>> events;
        for (int& w : vals[1]) {
            events.emplace_back(w, w, -1);
        }
        for (int i = 0; i < q; i++) {
            auto& [x, y] = points[i];
            events.emplace_back(x, y, i);
        }
        sort(events.begin(), events.end(), [&](auto& lhs, auto& rhs) {
            auto& [xl, yl, il] = lhs;
            auto& [xr, yr, ir] = rhs;
            if (xl == xr) {
                if (yl == yr) {
                    return il < ir;
                }
                return yl > yr;
            }
            return xl > xr;
        });
        SegmentTree<int> sgt(len + 1);
        for (auto& [x, y, id] : events) {
            int cy = comp.getId(y);
            if (id < 0) {
                sgt.modify(cy, 1);
            } else {
                int parity = sgt.rangeQuery(cy, len) & 1;
                ans[id] ^= parity;
            }
        }
    }
    // right
    {
        vector<tuple<int, int, int>> events;
        for (int& w : vals[2]) {
            events.emplace_back(w, w, -1);
        }
        for (int i = 0; i < q; i++) {
            auto& [x, y] = points[i];
            events.emplace_back(x, y, i);
        }
        sort(events.begin(), events.end(), [&](auto& lhs, auto& rhs) {
            auto& [xl, yl, il] = lhs;
            auto& [xr, yr, ir] = rhs;
            if (xl == xr) {
                if (yl == yr) {
                    return il < ir;
                }
                return yl < yr;
            }
            return xl < xr;
        });
        SegmentTree<int> sgt(len + 1);
        for (auto& [x, y, id] : events) {
            int cy = comp.getId(y);
            if (id < 0) {
                sgt.modify(cy, 1);
            } else {
                int parity = sgt.rangeQuery(1, cy) & 1;
                ans[id] ^= parity;
            }
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}