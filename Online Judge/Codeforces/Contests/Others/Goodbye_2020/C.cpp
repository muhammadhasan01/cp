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

const int N = 1e5 + 5;
const int K = 26;
const int INF = 2e9;

int n;
int a[N];
pair<int, int> dp[N][K];

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < K; j++) {
            dp[i][j] = make_pair(INF, -1);
        }
    }
}

void solve() {
    string s; cin >> s;
    n = s.length();
    for (int i = 1; i <= n; i++) {
        a[i] = (s[i - 1] - 'a');
    }
    init();
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < K; k++) {
                if (j == k) continue;
                if (dp[i - 1][k].second == (1 << j)) continue;
                int cur = dp[i - 1][k].first + (a[i] != j);
                if (cur < dp[i][j].first) {
                    dp[i][j].first = cur;
                    dp[i][j].second = (1 << k);
                } else if (cur == dp[i][j].first) {
                    dp[i][j].second |= (1 << k);
                }
            }
        }
    }
    int ans = INF;
    for (int k = 0; k < K; k++) {
        ans = min(ans, dp[n][k].first);
    }
    cout << ans << '\n';
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