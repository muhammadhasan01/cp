#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int N = 5e5 + 5;
const int TERM = 0;

struct Segtree {
    vector<int> t;
    Segtree() {
        t.assign(4 * N, 0);
    }

    int combine(const int& x, const int& y) {
        return (x > y ? x : y);
    }

    void build(int v, int s, int e) {
        if (s == e) {
            t[v] = 0;
        } else {
            int mid = (s + e) >> 1;
            build(v << 1, s, mid);
            build(v << 1 | 1, mid + 1, e);
            t[v] = combine(t[v << 1], t[v << 1 | 1]);
        }
    }

    void update(int v, int s, int e, int pos, int val) {
        if (s == e && s == pos) {
            t[v] = max(t[v], val);
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid)
            update(v << 1, s, mid, pos, val);
        else
            update(v << 1 | 1, mid + 1, e, pos, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    int query(int v, int s, int e, int l, int r) {
        if (e < l || s > r || l > r)
            return TERM;
        if (l <= s && e <= r)
            return t[v];
        int mid = (s + e) >> 1;
        int p1 = query(v << 1, s, mid, l, r);
        int p2 = query(v << 1 | 1, mid + 1, e, l, r);
        return combine(p1, p2);
    }
} sgt[2], t;

int n;
int a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int it = 0; it < 2; it++) sgt[it].build(1, 1, n);
    t.build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        t.update(1, 1, n, i, a[i]);
    }

    vector<int> euy(n + 1);
    vector<vector<int>> wow(n + 1);
    vector<vector<int>> vals(2, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        int l = 1, r = i - 1, pos = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (t.query(1, 1, n, mid, i - 1) > x) {
                l = mid + 1;
                pos = mid;
            } else {
                r = mid - 1;
            }
        }
        euy[i] = pos;
        if (pos != -1) wow[pos].emplace_back(x);
    }

    map<pair<int, int>, int> mp;
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        vals[0][x] = vals[1][x] = (i > 1 ? 2 : 1);
        for (int it = 0; it < 2; it++) {
            vals[0][x] = max(vals[0][x], 1 + sgt[it].query(1, 1, n, 1, x));
        }
        if (euy[i] != -1) {
            vals[1][x] = max(vals[1][x], 2 + mp[make_pair(euy[i], x)]);
        }
        for (int e : wow[i]) {
            int maks = 0;
            for (int it = 0; it < 2; it++) {
                maks = max(maks, sgt[it].query(1, 1, n, 1, e));
            }
            pair<int, int> dang = make_pair(i, e);
            mp[dang] = max(mp[dang], maks);
        }
        for (int it = 0; it < 2; it++) {
            sgt[it].update(1, 1, n, x, vals[it][x]);
        }
    }
    int answer = 0;
    for (int it = 0; it < 2; it++) {
        for (int i = 1; i <= n; i++) {
            answer = max(answer, vals[it][i]);
        }
    }
    cout << answer << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}