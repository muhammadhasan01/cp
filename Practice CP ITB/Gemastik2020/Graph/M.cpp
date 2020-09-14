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

const int M = 1e6;

struct edge {
    int u, v, id;
    edge(int u, int v, int id) : u(u), v(v), id(id) { }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> par(n), ans(m);
    iota(par.begin(), par.end(), 0);
    function<int(int)> fpar = [&](int u) {
        return (par[u] == u ? u : par[u] = fpar(par[u]));
    };
    function<void(int, int)> join_set = [&](int u, int v) {
        int pu = fpar(u);
        int pv = fpar(v);
        if (pu != pv)
            par[pv] = pu;
    };
    vector<vector<edge>> edges(M);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v, --w;
        edges[w].emplace_back(u, v, i);
    }
    vector<vector<pair<int, int>>> adj(n);
    vector<bool> vis(n);
    vector<int> tin(n), low(n);
    int timer = 0;
    map<pair<int, int>, int> cnt_edge; 
    function<void(int, int)> find_bridge = [&](int u, int p) {
        vis[u] = true;
        tin[u] = low[u] = ++timer;
        for (auto e : adj[u]) {
            int v = e.first;
            if (v == p) continue;
            if (vis[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                find_bridge(v, u);
                low[u] = min(low[u], low[v]);
                if (tin[u] < low[v] && cnt_edge[make_pair(u, v)] == 1)
                    ans[e.second] = 2;
            }
        }
    };
    for (int i = 0; i < M; i++) {
        if (edges[i].empty()) continue;
        vector<int> nodes;
        for (auto e : edges[i]) {
            int u = fpar(e.u), v = fpar(e.v);
            if (u == v) continue;
            debug() << imie(i) imie(u) imie(v) imie(e.id);
            nodes.emplace_back(u); nodes.emplace_back(v);
            ans[e.id] = 1;
            cnt_edge[make_pair(u, v)]++, cnt_edge[make_pair(v, u)]++;
            adj[u].emplace_back(v, e.id);
            adj[v].emplace_back(u, e.id);
        }
        for (int u : nodes) {
            if (vis[u]) continue;
            find_bridge(u, u);
        }
        cnt_edge.clear();
        timer = 0;
        for (int u : nodes) {
            adj[u].clear();
            vis[u] = tin[u] = low[u] = 0;
        }
        for (auto e : edges[i])
            join_set(e.u, e.v);
        debug() << imie(i) << imie(ans);
    }
    for (int i = 0; i < m; i++) {
        if (ans[i] == 0)
            cout << "none";
        else if (ans[i] == 1)
            cout << "at least one";
        else if (ans[i] == 2)
            cout << "any";
        cout << '\n';
    }

    return 0;
}