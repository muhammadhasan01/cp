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

const long long INF = 1e16;

long long m;

long long get(long long x) {
    long long ret = 0;
    while (x > 0) {
        ret += x / 5;
        x /= 5;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m;
    long long l = 5, r = INF, ans = -1;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (get(mid) >= m) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    if (get(ans) == m) {
        cout << 5 << '\n';
        for (int i = 0; i < 5; i++) {
            cout << ans + i << (i == 4 ? '\n' : ' ');
        }   
    } else {
        cout << 0 << '\n';
    }

    return 0;
}