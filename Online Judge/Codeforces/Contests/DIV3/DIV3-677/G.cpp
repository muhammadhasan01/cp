#include <bits/stdc++.h>

using namespace std;

/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void in(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void out(T n, char CC) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar(CC);
}
/** END OF DESPERATE OPTIMIZATION **/

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

const long long LINF = 1e18;
const int INF = 2e9;
const int N = 1e3 + 5;

int n, m, k;
vector<int> adj[N];
pair<int, int> edge[N], p[N];
int w[N][N];
int dist[N][N];
int res[N][N];

vector<int> dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dp(n + 1, INF);
    dp[s] = 0;
    pq.emplace(dp[s], s);
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int u = cur.second;
        if (cur.first != dp[u]) continue;
        for (int v : adj[u]) {
            if (dp[v] > dp[u] + w[u][v]) {
                dp[v] = dp[u] + w[u][v];
                pq.emplace(dp[v], v);
            }
        }
    }
    return dp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    in(n), in(m), in(k);
    for (int i = 1; i <= m; i++) {
        int u, v, _w;
        in(u), in(v), in(_w);
        edge[i] = make_pair(u, v);
        w[u][v] = w[v][u] = _w;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    for (int i = 1; i <= k; i++) {
        in(p[i].first), in(p[i].second);
    }
    for (int i = 1; i <= n; i++) {
        vector<int> cur = dijkstra(i);
        for (int j = 1; j <= n; j++) {
            dist[i][j] = cur[j];
        }
    }
    for (int i = 1; i <= m; i++) {
        int u = edge[i].first, v = edge[i].second;
        int curweight = w[u][v];
        w[u][v] = w[v][u] = 0;
        vector<int> cu = dijkstra(u), cv = dijkstra(v);
        for (int j = 1; j <= k; j++) {
            res[i][j] = min(cu[p[j].first] + cv[p[j].second], cu[p[j].second] + cv[p[j].first]);
        }
        w[u][v] = w[v][u] = curweight;
    }
    long long ans = LINF;
    for (int i = 1; i <= m; i++) {
        long long result = 0;
        for (int j = 1; j <= k; j++) {
            result += (1LL) * min(dist[p[j].first][p[j].second], res[i][j]);
        }
        ans = min(ans, result);
    }
    out(ans, '\n');

    return 0;
}