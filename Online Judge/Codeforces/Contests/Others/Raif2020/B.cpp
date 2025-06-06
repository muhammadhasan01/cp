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


void solve() {
    int n;
    cin >> n;
    vector<int> v(2);
    vector<int> ok(n);
    for (int i = 0; i < n; i++) {
        char cc; cin >> cc;
        if (cc == '-') {
            v[0]++, v[1]++;
            int j = (i + 1) % n;
            ok[i] = ok[j] = true;
        } else if (cc == '>') {
            v[0]++;
        } else if (cc == '<') {
            v[1]++;
        }
    }
    if (v[0] == n || v[1] == n) {
        cout << n << '\n';
        return;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (ok[i]) {
            ++res;
        }
    }
    cout << res << '\n';
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