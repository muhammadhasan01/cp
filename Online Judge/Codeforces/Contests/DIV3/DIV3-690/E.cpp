// Kamal Farras Imba Ane Cupu
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

const long long M = 1e9 + 7;

long long C(int a, int b) {
    if (a < b) return 0;
    assert(b == 3);
    long long ret = (1LL) * a * (a - 1) * (a - 2) / 6LL;
    return ret;
}

void solve() {
    int n, m = 3, k = 2;
    cin >> n;
    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pre[x]++;
    }
    for (int i = 1; i <= n; i++) {
        pre[i] += pre[i - 1];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = min(n, i + k);
        int cur = pre[j] - pre[i - 1];
        ans = (ans + C(cur, m));
        int now = pre[i] - pre[i - 1];
        ans = (ans - C(cur - now, m));
    }
    cout << ans << '\n';
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