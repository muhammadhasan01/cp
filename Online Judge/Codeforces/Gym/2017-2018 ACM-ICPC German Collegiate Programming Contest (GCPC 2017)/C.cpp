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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    const int INF = 2e9;

    int x;
    cin >> x;
    int n, m, T;
    cin >> n >> m >> T;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int> t(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
        adj[i].emplace_back(i);
    }
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, INF));
    vector<set<int>> times(x + 1);
    if (t[1] <= x) {
        times[t[1]].emplace(1);
        dp[1][t[1]] = p[1];
    }
    for (int tim = t[1]; tim <= x; tim++) {
        for (auto& e : times[tim]) {
            int u = e;
            int cost = dp[u][tim];
            for (int v : adj[u]) {
                int ntim = tim + (v != u ? T : 0) + t[v];
                if (ntim > x) continue;
                int ncost = cost + p[v];
                if (ncost >= dp[v][ntim]) continue;
                dp[v][ntim] = ncost;
                times[ntim].emplace(v);
            }
        }
    }
    if (dp[1][x] == INF) {
        cout << "It is a trap." << '\n';
        return 0;
    }
    cout << dp[1][x] << '\n';

    return 0;
}