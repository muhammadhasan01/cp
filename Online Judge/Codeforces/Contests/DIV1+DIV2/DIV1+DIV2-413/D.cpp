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

const long long INF = 1e12;
const long long N = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long a, b, h, w;
    int n;
    cin >> a >> b >> h >> w >> n;
    vector<long long> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p.rbegin(), p.rend());

    auto can = [&](int len) -> bool {
        vector<bool> dp(N + 5);
        dp[1] = 1;
        long long res = 1;
        for (int i = 0; i < len; i++) {
            res = min(INF, res * p[i]);
            for (int val = N; val > 0; val--) {
                if (dp[val]) {
                    dp[min(N, (1LL) * val * p[i])] = 1;
                }
            }
        }
        for (int val = 1; val <= N; val++) {
            if (!dp[val]) continue;
            long long oval = res / val;
            if (h * val >= a && w * oval >= b) return true;
            if (h * oval >= a && w * val >= b) return true;
        }
        return (h >= a && w >= b);
    };

    int l = 0, r = min(40, n), ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';

    return 0;
}