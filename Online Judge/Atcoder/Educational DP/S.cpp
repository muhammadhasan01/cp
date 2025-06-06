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
const int N = 1e4 + 5;
const int D = 1e2 + 5;

string k;
int d;
int dp[N][D][2]; // (index, modulo sum, 0: equal so far, 1: smaller guaranteed) => count

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> d;
    int n = k.length();
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int num = k[i - 1] - '0';
        for (int v = 0; v < d; v++) {
            for (int j = 0; j < 10; j++) {
                for (int smaller = 0; smaller < 2; smaller++) {
                    if (!smaller && j > num) continue;
                    int& cur = dp[i][(v + j) % d][(smaller || j < num)];
                    cur = (cur + dp[i - 1][v][smaller]) % M;
                }
            }
        }
    }
    int ans = ((dp[n][0][0] + dp[n][0][1] - 1) % M + M) % M;
    cout << ans << '\n';

    return 0;
}