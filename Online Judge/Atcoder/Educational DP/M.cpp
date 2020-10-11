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

const int N = 1e2 + 5;
const int K = 1e5 + 5;
const int M = 1e9 + 7;

int n, k;
int a[N];
int dp[N][K], pre[N][K];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int val = 0; val <= k; val++) {
        dp[1][val] = (val <= a[1]);
        pre[1][val] = dp[1][val];
        if (val) pre[1][val] += pre[1][val - 1];
    }
    for (int i = 2; i <= n; i++) {
        for (int val = 0; val <= k; val++) {
            if (val - a[i] - 1 < 0)
                dp[i][val] = pre[i - 1][val];
            else
                dp[i][val] = ((pre[i - 1][val] - pre[i - 1][val - a[i] - 1]) % M + M) % M;
        }
        pre[i][0] = dp[i][0];
        for (int val = 1; val <= k; val++) {
            pre[i][val] = (pre[i][val - 1] + dp[i][val]) % M;
        }
    }
    cout << dp[n][k] << '\n';

    return 0;
}