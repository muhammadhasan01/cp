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

const int R = 5e5 + 5;
const long double EPS = 1e-14;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long double x, y, r;
    cin >> x >> y >> r;
    r += EPS;

    auto f = [&](long double x) -> long double {
        return x * x;
    };

    long double rr = f(r);
    long long ans = 0;
    for (int it = -R; it <= R; it++) {
        long double cy = it;
        long double cur = rr - f(cy - y);
        if (cur < 0) continue;
        cur = sqrtl(cur);
        long double up = cur + x;
        long double dwn = -cur + x;
        ans += max(0LL, (long long) (floor(up) - ceil(dwn)) + 1);
    }
    cout << ans << '\n';

    return 0;
}