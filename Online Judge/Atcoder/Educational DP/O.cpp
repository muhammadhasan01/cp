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

const int M = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> mask_len(n + 1);
    for (int mask = 0; mask < (1 << n); mask++) {
        int len = __builtin_popcount(mask);
        mask_len[len].emplace_back(mask);
    }
    vector<vector<int>> dp(n + 1, vector<int>((1 << n)));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int mask : mask_len[i]) {
            for (int j = 0; j < n; j++) {
                if (a[i][j + 1] == 0) continue;
                bool bit = (mask & (1 << j));
                if (!bit) continue;
                int bmask = (mask ^ (1 << j));
                dp[i][mask] = (dp[i][mask] + dp[i - 1][bmask]) % M;
            }
        }
    }
    cout << dp[n][(1 << n) - 1] << '\n';

    return 0;
}