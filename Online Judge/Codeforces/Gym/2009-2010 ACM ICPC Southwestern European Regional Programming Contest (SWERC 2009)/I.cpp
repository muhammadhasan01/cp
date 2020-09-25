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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            cin >> x >> y;
            v[i] = make_pair(x, x + y);
        }
        debug() << imie(v);
        auto check = [&](pair<int, int> x, pair<int, int> y) -> bool {
            if (x.first > y.first) swap(x, y);
            return (x.second <= y.first || x.first >= y.second);
        };
        int res = 0;
        for (int i = 0; i < m; i++) {
            pair<int, int> p; cin >> p.first >> p.second;
            p.second += p.first;
            int res = 0;
            for (int j = 0; j < n; j++) {
                if (check(p, v[j])) continue;
                debug() << imie(i) imie(j) imie(p) imie(v[j]);
                ++res;
            }
            cout << res << '\n';
        }
    }

    return 0;
}