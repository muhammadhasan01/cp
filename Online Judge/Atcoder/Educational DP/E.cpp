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

const int V = 1e5 + 5;
const int INF = 1e9 + 100;

int n, max_w;
int dp[V];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < V; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;
    cin >> n >> max_w;
    for (int i = 1; i <= n; i++) {
        int w, v;
        cin >> w >> v;
        for (int j = V - 1; j >= 0; j--) {
            int k = j + v;
            if (k < V) {
                dp[k] = min(dp[k], dp[j] + w);
            }
        }
    }
    for (int v = V - 1; v >= 0; v--) {
        if (dp[v] <= max_w) {
            cout << v << '\n';
            return 0;
        }
    }

    return 0;
}