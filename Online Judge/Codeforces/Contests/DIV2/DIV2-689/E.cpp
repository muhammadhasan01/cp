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

const long long INF = 1e18 + 100;

long long k, l, r, t, x, y;
long long bound;
unordered_map<long long, bool> mp;

long long get(long long u, bool can_add) {
    if (mp[u] == 1) return INF;
    mp[u] = 1;
    if (can_add && u + y <= r) {
        return min(INF, get(u + y, false));
    }
    if (u - x < l) return 1;
    long long cur = l + (u - l) % x;
    long long day = (u - cur) / x;
    long long ret = min(INF, day + get(cur, true));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> l >> r >> t >> x >> y;
    bound = min(r, l + x - 1);
    long long res = get(k, true);
    cout << (res > t ? "Yes" : "No") << '\n';

    return 0;
}