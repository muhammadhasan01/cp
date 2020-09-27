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

const int N = 2e3 + 5;
const int K = 9;
const int M = 1e9 + 7;

int n, e, k;
int dp[N][(1 << K)];
bool bad[N][N];

int get(int mask, int k) {
    mask ^= (1 << k);
    return (mask << 1 | 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> e >> k;
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        bad[u][v] = 1;
    }
    dp[0][(1 << (e + 1)) - 1] = 1;
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << (2 * e + 1)); mask++) {
            if (dp[i][mask] == 0) continue;
            for (int k = 0; k <= 2 * e; k++) {
                int pos = i + e - k;
                if (pos >= n && pos < 0) continue;
                if (bad[i][pos]) continue;
                if (!(mask & (1 << k))) continue;
                int nmask = get(mask, k);
                dp[i + 1][nmask] = (dp[i + 1][nmask] + dp[i][mask]) % M;
            }
        }
    }
    cout << dp[n][(1 << (e + 1)) - 1] << '\n';

    return 0;
}