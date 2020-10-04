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

const int INF = 1e7;

int n, k, d, t;

bool can(int x) {
    int ret = (x / t) * k;
    ret += (max(0, x - d)) / t * k;
    return (ret >= n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t >> k >> d;
    int res = (n + k - 1) / k * t;
    int l = 1, r = INF, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    debug() << imie(res) imie(ans);
    cout << (res > ans ? "YES" : "NO") << '\n';
 
    return 0;
}