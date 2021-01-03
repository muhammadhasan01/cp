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

const int INF = 1e7;
const int V = 3e5 + 5;
const int N = 1e3 + 5;

int n, k;
bool a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        a[x] = 1;
    }
    if (a[n]) {
        cout << 1 << '\n';
        return 0;
    }
    vector<vector<int>> v(2);
    for (int i = 0; i < N; i++) {
        if (!a[i]) continue;
        v[(i >= n)].emplace_back(abs(n - i));
    }
    vector<vector<int>> dp(2, vector<int>(V, INF));
    for (int it = 0; it < 2; it++) {
        dp[it][0] = 0;
        for (int x : v[it]) {
            for (int val = x; val < V; val++) {
                int bval = val - x;
                dp[it][val] = min(dp[it][val], dp[it][bval] + 1);
            }
        }
    }
    int ans = INF;
    for (int val = 1; val < V; val++) {
        ans = min(ans, dp[0][val] + dp[1][val]);
    }
    if (ans == INF) ans = -1;
    cout << ans << '\n';

    return 0;
}