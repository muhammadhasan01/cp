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

    const long long INF = 1e18;

    int n, m, r, c;
    cin >> n >> m >> r >> c;
    vector<vector<int>> a(r + 1, vector<int>(c + 1));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> a[i][j];
        }
    }

    auto ceil = [&](int x, int y) -> int {
        return (x + y - 1) / y;
    };

    vector<vector<int>> dp(r + 1, vector<int>(c + 1));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            dp[i][j] = ceil(n - i + 1, r) * ceil(m - j + 1, c);
        }
    }
    long long ans = INF;
    for (int x = 1; x <= r; x++) {
        for (int y = 1; y <= c; y++) {
            long long cur = 0;
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    int px = (i + x - 1) % r, py = (j + y - 1) % c;
                    if (px == 0) px = r;
                    if (py == 0) py = c;
                    cur += (1LL) * dp[px][py] * a[i][j];
                }
            }
            ans = min(ans, cur);
        }
    }
    cout << ans << "\n";

    return 0;
}