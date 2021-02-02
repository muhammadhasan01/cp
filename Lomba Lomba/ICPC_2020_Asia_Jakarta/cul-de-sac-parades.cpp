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

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    vector<vector<long long>> dp(n, vector<long long>(2, -1));

    function<long long(int, int, bool)> dfs = [&](int u, int p, bool path = false) {
        if (dp[u][path] != -1)
            return dp[u][path];
        vector<pair<long long, long long>> data;
        for (auto& e : adj[u]) {
            int v = e.first;
            if (v == p) continue;
            int w = e.second;
            long long x = dfs(v, u, true) + w;
            long long y = dfs(v, u, false);
            data.emplace_back(x, y);
        }
        if (data.empty()) return dp[u][path] = 0;
        sort(data.begin(), data.end(), [&](auto& x, auto& y) {
            return x.first - x.second > y.first - y.second;
        });
        long long ret = 0;
        for (auto& e : data) ret += e.second;
        if (path) ret += data[0].first - data[0].second;
        int len = data.size();
        for (int i = path; i + 1 < len; i += 2) {
            long long x = data[i].first + data[i + 1].first;
            long long y = data[i].second + data[i + 1].second;
            if (x < y) break;
            ret += x - y;
        }
        return dp[u][path] = ret;
    };

    long long ans = dfs(0, 0, false);
    if ((int) adj[0].size() == 1)
        ans = max(ans, dfs(0, 0, true));
    cout << ans << '\n';

    return 0;
}