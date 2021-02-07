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

using pli = pair<long long, int>;

const int N = 2e5 + 5;
const long long INF = 1e18;

int n, m;
vector<pair<int, int>> adj[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    auto get = [&](int s) -> long long {
        vector<long long> dist(n + 1, INF);
        priority_queue<pli, vector<pli>, greater<>> pq;
        pq.emplace(0, s);
        while (!pq.empty()) {
            long long dis; int u;
            tie(dis, u) = pq.top(); pq.pop();
            if (dist[u] != INF && dis != dist[u]) continue;
            if (u == s && dist[u] != INF) break;
            for (auto& e : adj[u]) {
                int v = e.first;
                long long w = e.second;
                if (dist[v] > dis + w) {
                    dist[v] = dis + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        if (dist[s] == INF) dist[s] = -1;
        return dist[s];
    };

    for (int i = 1; i <= n; i++) {
        cout << get(i) << '\n';
    }

    return 0;
}