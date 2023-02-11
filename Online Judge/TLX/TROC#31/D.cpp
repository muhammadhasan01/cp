#include <bits/stdc++.h>

using namespace std;

template<int MAXN, typename T, const T& TERM>
struct Segtree {
    vector<T> t;
    Segtree() {
        t.assign(4 * MAXN, TERM);
    }

    T combine(const T& x, const T& y) {
        return (x > y ? x : y);
    }

    void build(int v, int s, int e, vector<T>& a) {
        if (s == e) {
            t[v] = a[s];
        } else {
            int mid = (s + e) >> 1;
            build(v << 1, s, mid, a);
            build(v << 1 | 1, mid + 1, e, a);
            t[v] = combine(t[v << 1], t[v << 1 | 1]);
        }
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

const int N = 1e5 + 5;
const pair<int, int> INF = make_pair(-2e9, -2e9);
Segtree<N, pair<int, int>, INF> sgt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].second;
    }
    sort(v.begin(), v.end(), [&](auto& l, auto& r) {
        if (l.first == r.first) {
            return l.second > r.second;
        }
        return l.first > r.first;
    });
    int maks = 0;
    for (int i = 0; i < n; i++) {
        sgt.update(1, 0, n - 1, i, make_pair(v[i].second, i));
        maks = max(maks, v[i].first);
    }
    long long ans = 0;
    for (int cur = maks; cur >= 1; cur--) {
        int at = -1;
        {
            int l = 0, r = n - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (v[mid].first >= cur) {
                    l = mid + 1;
                    at = mid;
                } else {
                    r = mid - 1;
                }
            }
        }
        auto [val, pos] = sgt.get(1, 0, n - 1, 0, at);
        ans += val;
        if (val > 0) {
            sgt.update(1, 0, n - 1, pos, make_pair(0, pos));
        }
    }
    cout << ans << '\n';
    
    return 0;
}