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

const int N = 1e3 + 5;

int tc;
int n;
char s[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    bool odd = false;
    for (int i = 1; i <= n; i += 2) {
        int x = s[i] - '0';
        if (x & 1) {
            odd = true;
            break;
        }
    }
    bool even = false;
    for (int i = 2; i <= n; i += 2) {
        int x = s[i] - '0';
        if (!(x & 1)) {
            even = true;
            break;
        }
    }
    if (n & 1) {
        cout << (odd ? 1 : 2) << '\n';
    } else {
        cout << (even ? 2 : 1) << '\n';
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