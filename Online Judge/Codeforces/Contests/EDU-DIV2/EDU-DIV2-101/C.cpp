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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n + 1), low(n + 1), high(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    low[1] = high[1] = h[1];
    for (int i = 2; i <= n; i++) {
        low[i] = max(low[i - 1] - k + 1, h[i]);
        high[i] = min(high[i - 1] + k - 1, h[i] + k - 1);
        if ((low[i] >= h[i] + k) || (low[i - 1] - high[i] >= k) || (low[i] - high[i - 1] >= k)) {
            cout << "NO" << '\n';
            return;
        }
        
    }
    cout << (low[n] == h[n] ? "YES" : "NO") << '\n';
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