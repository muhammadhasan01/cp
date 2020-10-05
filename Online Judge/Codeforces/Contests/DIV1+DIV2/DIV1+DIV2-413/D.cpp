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

    const int INF = 1e5;

    int A, B, H, W;
    cin >> A >> B >> H >> W;
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p.rbegin(), p.rend());
    n = min(n, 40);

    auto solve = [&](int a, int b, int h, int w) -> int {
        a = (a + h - 1) / h;
        b = (b + w - 1) / w;
        if (a == 1 && b == 1) return 0;
        vector<int> dp(a + 1);
        dp[1] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = a; j > 0; j--) {
                int res = min((1LL) * j * p[i], (1LL) * a);
                dp[res] = min(b, max(dp[res], dp[j]));
                dp[j] = min((1LL) * b, (1LL) * dp[j] * p[i]);
            }
            if (dp[a] >= b)
                return i + 1;
        }
        return INF;
    };

    int res = min(solve(A, B, H, W), solve(A, B, W, H));
    if (res == INF)
        res = -1;
    cout << res << '\n';

    return 0;
}