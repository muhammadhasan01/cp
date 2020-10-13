#include <bits/stdc++.h>

using namespace std;

/** START OF TEMPLATE DEBUGGER **/
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
/** END OF TEMPLATE DEBUGGER **/

const int N = 2e5 + 5;

int n;
int h[N], a[N];
long long t[4 * N];

void update(int v, int s, int e, int pos, long long val) {
    if (s == e && s == pos) {
        t[v] = max(t[v], val);
        return;
    }
    int mid = (s + e) >> 1;
    if (pos <= mid)
        update(v << 1, s, mid, pos, val);
    else
        update(v << 1 | 1, mid + 1, e, pos, val);
    t[v] = max(t[v << 1], t[v << 1 | 1]);
}

long long get(int v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return 0LL;
    if (l <= s && e <= r) return t[v];
    int mid = (s + e) >> 1;
    long long p1 = get(v << 1, s, mid, l, r);
    long long p2 = get(v << 1 | 1, mid + 1, e, l, r);
    return max(p1, p2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long cur = a[i] + get(1, 1, n, 1, h[i] - 1);
        update(1, 1, n, h[i], cur);
        ans = max(ans, cur);
    }
    cout << ans << '\n';

    return 0;
}