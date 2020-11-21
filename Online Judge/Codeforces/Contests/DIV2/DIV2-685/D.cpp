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

long long d, k;

void solve() {
    cin >> d >> k;
    vector<int> cnt(2);
    long long res_x = -1, res_y = -1;
    for (long long x = 0; x <= d; x += k) {
        long long res = d * d - x * x;
        long long l = 0, r = (d + k - 1) / k, at = 0;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            long long cur = mid * k;
            if (cur * cur <= res) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        long long y = at * k;
        if (x > y || (x + k) * (x + k) + y * y <= d * d) continue;
        res_x = x, res_y = y;
    }
    debug() << imie(res_x) imie(res_y);
    cout << (res_y > res_x ? "Ashish" : "Utkarsh") << '\n';
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