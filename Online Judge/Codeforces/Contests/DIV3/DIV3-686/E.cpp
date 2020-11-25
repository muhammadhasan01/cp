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

const int N = 2e5 + 5;

int n;
vector<int> adj[N];
char color[N];
int parent[N];
int cycle_start, cycle_end;
bool inCycle[N];
int sz[N], deg[N];

void init() {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        color[i] = 0; parent[i] = -1;
        inCycle[i] = 0; sz[i] = 1;
        deg[i] = 0;
    }
    cycle_start = -1;
}

bool dfs(int v, int par) { // passing vertex and its parent vertex
    color[v] = 1;
    for (int u : adj[v]) {
        if (u == par) continue; // skipping edge to parent vertex
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u, parent[u]))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void solve() {
    cin >> n;
    init();
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        deg[u]++, deg[v]++;
    }
    for (int v = 1; v <= n; v++) {
        if (color[v] == 0 && dfs(v, parent[v]))
            break;
    }
    vector<int> cycle;
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v])
        cycle.push_back(v);
    debug() << imie(cycle);
    for (int v : cycle) {
        inCycle[v] = v;
    }
    queue<int> q;
    for (int v = 1; v <= n; v++) {
        if (deg[v] == 1)
            q.emplace(v);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            sz[u] += sz[v];
            if (--deg[u] == 1 && !inCycle[u]) {
                q.emplace(u);
            }
        }
    }
    long long ans = (1LL) * n * (n - 1) / 2;
    long long res = 0;
    for (int v : cycle) {
        debug() << imie(v) imie(sz[v]) imie(n - sz[v]);
        res += (1LL) * (n - sz[v]) * sz[v];
    }
    res /= 2;
    cout << ans + res << '\n';
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