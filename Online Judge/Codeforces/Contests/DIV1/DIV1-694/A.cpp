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

    void build(int v, int s, int e, vector<int>& a) {
        if (s == e) {
            t[v] = make_pair(a[s], s);
        } else {
            int mid = (s + e) >> 1;
            build(v << 1, s, mid, a);
            build(v << 1 | 1, mid + 1, e, a);
            t[v] = combine(t[v << 1], t[v << 1 | 1]);
        }
    }

    void update(int v, int s, int e, int pos, int val) {
        if (s == e && s == pos) {
            t[v].first = val;
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

const int INF = 2e9;
const int N = 3e5 + 5;
const pair<int, int> TERM = make_pair(INF, -1);

Segtree<N, pair<int, int>, TERM> sgt;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        k[i]--;
    }
    vector<int> c(m);
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += c[k[i]];
    }
    sgt.build(1, 0, m - 1, c);
    sort(k.begin(), k.end(), [&](int i, int j) {
        return c[i] > c[j];
    });
    for (int pos : k) {
        auto [val, id] = sgt.get(1, 0, m - 1, 0, pos - 1);
        if (val >= c[pos]) {
            continue;
        }
        ans += (val - c[pos]);
        sgt.update(1, 0, m - 1, id, INF);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}