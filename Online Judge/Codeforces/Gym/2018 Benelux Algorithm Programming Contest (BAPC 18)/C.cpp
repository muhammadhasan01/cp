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

const long long INF = 1e18;

int val;

long long F(long long a, long long b, long long c) {
    return 2LL * (a * b + b * c + a * c);
}

long long get(int x) {
    long long ret = INF;
    int y = val / x;
    for (int i = 1; i * i <= y; i++) {
        if (y % i == 0) {
            long long cur = F(x, i, y / i);
            debug() << imie(x) imie(i) imie(y / i) imie(cur);
            ret = min(ret, cur);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> val;
    long long ans = INF;
    for (int i = 1; i * i <= val; i++) {
        if (val % i == 0) {
            ans = min(ans, get(i));
            ans = min(ans, get(val / i));
            debug() << imie(i) imie(ans);
        }
    }
    cout << ans << '\n';

    return 0;
}