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

const int N = 1e5 + 5;

const long long TERM = -1e18;

struct SegtreeLazy {
    vector<long long> t;
    vector<long long> lazy;
    SegtreeLazy() {
        t.assign(4 * N, 0);
        lazy.assign(4 * N, 0);
    }

    long long combine(const long long& x, const long long& y) {
        return (x > y ? x : y);
    }

    void build(int v, int s, int e) {
        lazy[v] = 0;
        if (s == e) {
            t[v] = 0;
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    void push(int v, int s, int e) {
        if (lazy[v] == 0 || s == e) return;
        t[v << 1] += lazy[v];
        t[v << 1 | 1] += lazy[v];
        lazy[v << 1] += lazy[v];
        lazy[v << 1 | 1] += lazy[v];
        lazy[v] = 0;
    }

    void update(int v, int s, int e, int l, int r, long long val) {
        if (l > r) return;
        if (l == s && e == r) {
            t[v] += val;
            lazy[v] += val;
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        update(v << 1, s, mid, l, min(r, mid), val);
        update(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    long long get(int v, int s, int e, int l, int r) {
        if (l > r)
            return TERM;
        if (l <= s && e <= r)
            return t[v];
        push(v, s, e);
        int mid = (s + e) >> 1;
        long long p1 = get(v << 1, s, mid, l, min(r, mid));
        long long p2 = get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
        return combine(p1, p2);
    }
} sgt;

int n, q;

void solve() {
    cin >> n >> q;
    sgt.build(1, 1, n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        sgt.update(1, 1, n, l, r, 1);
        if (r + 1 <= n) sgt.update(1, 1, n, r + 1, r + 1, -(r - l + 1));
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += sgt.get(1, 1, n, i, i);
        cout << ans << (i == n ? '\n' : ' ');
    }
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