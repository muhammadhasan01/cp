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

const int N = 3e5 + 5;

int tc;
int n, q;
int a[N];
long long res;

void upd(int pos, int val) {
    res -= max(0, a[pos] - a[pos - 1]);
    if (pos + 1 <= n) res -= max(0, a[pos + 1] - a[pos]);
    a[pos] = val;
    res += max(0, a[pos] - a[pos - 1]);
    if (pos + 1 <= n) res += max(0, a[pos + 1] - a[pos]);
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    res = a[1];
    for (int i = 2; i <= n; i++) {
        res += (1LL) * max(0, a[i] - a[i - 1]); 
    }
    cout << res << '\n';
    while (q--) {
        int l, r;
        cin >> l >> r;
        int x = a[l], y = a[r];
        upd(l, y); upd(r, x);
        cout << res << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}