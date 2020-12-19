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
const long long INF = 1e16;

int n;
int a[N];
long long dp[N], t[4 * N];

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = INF;
        return;
    }
    int mid = (s + e) >> 1;
    build(v + v, s, mid);
    build(v + v + 1, mid + 1, e);
    t[v] = min(t[v + v], t[v + v + 1]);
}

void update(int v, int s, int e, int pos, long long val) {
    if (s == e && s == pos) {
        t[v] = val;
        return;
    }
    int mid = (s + e) >> 1;
    if (pos <= mid)
        update(v + v, s, mid, pos, val);
    else
        update(v + v + 1, mid + 1, e, pos, val);
    t[v] = min(t[v + v], t[v + v + 1]);
}

long long get(int v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return INF;
    if (l <= s && e <= r) return t[v];
    int mid = (s + e) >> 1;
    return min(get(v + v, s, mid, l, r), get(v + v + 1, mid + 1, e, l, r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    update(1, 1, n, n, n);
    for (int i = n - 1; i >= 1; i--) {
        long long cur = get(1, 1, n, i + 1, a[i]);
        dp[i] = cur + (n - a[i] - i);
        update(1, 1, n, i, dp[i] + i);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i];
    }
    cout << ans << '\n';

    return 0;
}