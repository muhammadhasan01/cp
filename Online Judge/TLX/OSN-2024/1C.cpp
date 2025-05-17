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
    int L;
    int R;
    int U;
    int D;
    Info() {
        L = INT_MAX;
        R = -INT_MAX;
        U = -INT_MAX;
        D = INT_MAX;
    }
    Info(pair<int, int> v) {
        U = D = v.first;
        L = R = v.second;
    }
};

Info operator+(const Info& lhs, const Info& rhs) {
    Info info;
    info.L = min(lhs.L, rhs.L);
    info.R = max(lhs.R, rhs.R);
    info.U = max(lhs.U, rhs.U);
    info.D = min(lhs.D, rhs.D);
    return info;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int area = n * m;
    vector<pair<int, int>> pos(area);
    vector<vector<int>> a(n, vector<int>(m));
    vector<Info> init(area);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            pos[x] = {i, j};
            a[i][j] = x;
            init[x] = Info(pos[x]);
        }
    }
    SegmentTree<Info> sgt(init);
    int cursor = 0;
    int q;
    cin >> q;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            --r1, --c1, --r2, --c2;
            int v1 = a[r1][c1];
            int v2 = a[r2][c2];
            Info info1 = Info(pos[v1]);
            Info info2 = Info(pos[v2]);
            sgt.modify(v1, info2);
            sgt.modify(v2, info1);
            swap(pos[v1], pos[v2]);
            swap(a[r1][c1], a[r2][c2]);
        } else if (tp == 2) {
            int w;
            cin >> w;
            cursor -= w;
            if (cursor < 0) {
                cursor += area;
            }
        } else if (tp == 3) {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            --r1, --c1, --r2, --c2;

            auto can = [&](int len) -> bool {
                int lft1 = cursor;
                int rgt1 = min(area - 1, cursor + len - 1);
                Info info = sgt.rangeQuery(lft1, rgt1);
                if (cursor + len - 1 >= area) {
                    int lft2 = 0;
                    int rgt2 = (cursor + len - 1) % area;
                    info = info + sgt.rangeQuery(lft2, rgt2);
                }
                if (info.L < c1 || info.R > c2 || info.U > r2 || info.D < r1) {
                    return true;
                }
                return false;
            };

            int l = 1, r = area, ans = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (can(mid)) {
                    r = mid - 1;
                    ans = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            cout << ans << '\n';
        }
    }
    
    return 0;
}