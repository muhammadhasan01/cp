#include <bits/stdc++.h>

using namespace std;

template<int MAXN, typename T, const T& TERM>
struct Segtree {
    vector<T> t;
    Segtree() {
        t.assign(4 * MAXN, TERM);
    }

    T combine(const T& x, const T& y) {
        return (x < y ? x : y);
    }

    void update(int v, int s, int e, int pos, T val) {
        if (s == e && s == pos) {
            t[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid)
            update(v << 1, s, mid, pos, val);
        else
            update(v << 1 | 1, mid + 1, e, pos, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    T get(int v, int s, int e, int l, int r) {
        if (e < l || s > r || l > r)
            return TERM;
        if (l <= s && e <= r)
            return t[v];
        int mid = (s + e) >> 1;
        T p1 = get(v << 1, s, mid, l, r);
        T p2 = get(v << 1 | 1, mid + 1, e, l, r);
        return combine(p1, p2);
    }
};

const int N = 2500 + 5;
const int INF = 1e9;

int n, z;
long double k;
pair<int, int> p[N];
Segtree<N, int, INF> sgt[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> z >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].second >> p[i].first;
    }
    sort(p + 1, p + 1 + n);
    auto can = [&](int dx, int dy) -> bool {
        return (long double) dy >= (long double) k * dx;
    };
    sgt[p[1].first].update(1, 1, z, p[1].second, 0);
    for (int i = 2; i <= n; i++) {
        auto [y, x] = p[i];
        auto [by, bx] = p[i - 1];
        int dy = abs(y - by);
        for (int j = 1; j <= z; j++) {
            int lft = -1, rgt = -1;
            {
                int l = 1, r = j, at = j;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    int dx = abs(j - mid);
                    if (can(dx, dy)) {
                        r = mid - 1;
                        at = mid;
                    } else {
                        l = mid + 1;
                    }
                }
                lft = at;
            }
            {
                int l = j, r = z, at = j;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    int dx = abs(j - mid);
                    if (can(dx, dy)) {
                        l = mid + 1;
                        at = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                rgt = at;
            }
            int cur = sgt[by].get(1, 1, z, lft, rgt);
            if (cur == INF) {
                continue;
            }
            cur += abs(j - x);
            sgt[y].update(1, 1, z, j, cur);
        }
    }
    cout << sgt[p[n].first].get(1, 1, z, p[n].second, p[n].second) << '\n';

    return 0;
}