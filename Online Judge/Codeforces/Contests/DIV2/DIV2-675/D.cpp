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

const int M = 1e5 + 5;
const int INF = 2e9 + 100;

int n, m;
int sx, sy, fx, fy;
pair<pair<int, int>, int> p[M];
vector<pair<int, int>> adj[M];

int djikstra() {
    vector<int> dist(m + 2, INF);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> par(m + 2);
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int u = cur.second, dis = cur.first;
        if (dist[u] != dis) continue;
        for (auto& e : adj[u]) {
            int v = e.first;
            int w = e.second;
            if (dist[v] == INF || dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
                par[v] = u;
            }
        }
    }
    return dist[m + 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> sx >> sy >> fx >> fy;
    int ans = abs(sx - fx) + abs(sy - fy);
    for (int i = 1; i <= m; i++) {
        cin >> p[i].first.first >> p[i].first.second;
        p[i].second = i;
    }
    for (int i = 1; i <= m; i++) {
        {
            int cur = min(abs(sx - p[i].first.first), abs(sy - p[i].first.second));
            adj[0].emplace_back(i, cur);
            adj[i].emplace_back(0, cur);
        }
        {
            int cur = abs(fx - p[i].first.first) + abs(fy - p[i].first.second);
            adj[m + 1].emplace_back(i, cur);
            adj[i].emplace_back(m + 1, cur);
        }
    }
    sort(p + 1, p + 1 + m, [&](auto& x, auto& y) {
        return (x.first.first < y.first.first);
    });
    for (int i = 2; i <= m; i++) {
        adj[p[i].second].emplace_back(p[i - 1].second, p[i].first.first - p[i - 1].first.first);
        adj[p[i - 1].second].emplace_back(p[i].second, p[i].first.first - p[i - 1].first.first);
    }
    sort(p + 1, p + 1 + m, [&](auto& x, auto& y) {
        return (x.first.second < y.first.second);
    });
    for (int i = 2; i <= m; i++) {
        adj[p[i].second].emplace_back(p[i - 1].second, p[i].first.second - p[i - 1].first.second);
        adj[p[i - 1].second].emplace_back(p[i].second, p[i].first.second - p[i - 1].first.second);
    }
    ans = min(ans, djikstra());
    cout << ans << '\n';

    return 0;
}