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
#ifdef LOCALE
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

struct SCC {
    int n;
    vector<vector<int>> adj;
    vector<int> comp;
    int numComponent = 0;
    
    SCC(int t_n) : n(t_n), adj(t_n), comp(t_n, -1) {}
    SCC(const vector<vector<int>>& t_adj) : adj(t_adj) {
        n = t_adj.size();
        comp.assign(n, -1);
    }
 
    void addEdge(int u, int v) {
        adj[u].emplace_back(v);
    }
 
    void build(bool isDirected) {
        vector<int> tin(n), low(n);
        vector<bool> onStack(n);
        stack<int> st;
        int timer = 0;
        function<void(int, int)> tarjan = [&](int u, int p) {
            tin[u] = low[u] = ++timer;
            st.emplace(u);
            onStack[u] = true;
            for (int v : adj[u]) {
                if (!isDirected && v == p) {
                    continue;
                }
                if (tin[v] == 0) {
                    tarjan(v, u);
                    low[u] = min(low[u], low[v]);
                } else if (onStack[v]) {
                    low[u] = min(low[u], tin[v]);
                }
            }
            if (tin[u] != low[u]) {
                return;
            }
            int w = 0;
            do {
                w = st.top();
                st.pop();
                onStack[w] = 0;
                comp[w] = numComponent;
            } while (w != u && !st.empty());
            numComponent++;
        };
        for (int u = 0; u < n; u++) {
            if (tin[u] == 0) {
                tarjan(u, u);
            }
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    SCC scc(n + 1);
    vector<pair<int, int>> edges(m + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        if (u == v) {
            continue;
        }
        scc.addEdge(u, v);
    }
    scc.build(true);
    vector<vector<int>> comps(n + 1);
    vector<long long> vals(n + 1);
    for (int u = 1; u <= n; u++) {
        int cc = scc.comp[u];
        comps[cc].emplace_back(u);
        debug() << imie(u) imie(cc);
        vals[cc] += a[u];
    }
    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1);
    for (int i = 1; i <= m; i++) {
        auto [u, v] = edges[i];
        if (scc.comp[u] == scc.comp[v]) {
            continue;
        }
        adj[scc.comp[u]].emplace_back(scc.comp[v]);
        debug() << imie(scc.comp[u]) imie(scc.comp[v]);
        deg[scc.comp[v]]++;
    }
    vector<int> par(n + 1);
    vector<pair<int, long long>> dp(n + 1, {0, 0LL});
    queue<int> q;
    for (int u = 1; u <= n; u++) {
        if (comps[u].empty()) {
            continue;
        }
        debug() << imie(comps[u]) imie(vals[u]) imie(deg[u]);
        if (deg[u] == 0) {
            q.emplace(u);
            dp[u] = {(int) comps[u].size(), -vals[u]};
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            dp[v] = max(dp[v], {(int) comps[v].size() + dp[u].first, -vals[v] + dp[u].second});
            if (--deg[v] == 0) {
                q.emplace(v);
            }
        }
    }
    pair<int, long long> opt = {0, 0LL};
    for (int u = 1; u <= n; u++) {
        if (comps[u].empty()) {
            continue;
        }
        opt = max(opt, dp[u]);
    }
    cout << opt.first << ' ' << -opt.second << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}