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

const int INF = 2e9;
const int N = 3e6 + 5;
const int M = 1e9 + 7;
const int K = 30;

int n, m, k;
int bfr[K];
char s[N];
long long dp[N], pre[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    cin >> (s + 1);
    m = strlen(s + 1); 
    dp[0] = pre[0] = 1;
    for (int i = 1; i <= n + m; i++) {
        int x;
        if (i > m) {
            int lowest = INF;
            for (int v = 0; v < k; v++) {
                if (bfr[v] < lowest) {
                    lowest = bfr[v];
                    x = v;
                }
            }
        } else {
            x = (s[i] - 'a');
        }
        if (bfr[x] == 0)
            dp[i] = pre[i - 1];
        else
            dp[i] = (pre[i - 1] - pre[bfr[x] - 1]) % M;
        dp[i] = (dp[i] % M + M) % M;
        pre[i] = (pre[i - 1] + dp[i]) % M;
        bfr[x] = i;
    }
    cout << pre[n + m] << '\n';

    return 0;
}