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

const int N = 1e5 + 5;
const int L = 20;

int n, m;
int up[N][L];
int tin[N], low[N], timer = 0;
int comp[N], numComponent;
int deg[N], par[N];
bool onStack[N];
stack<int> st;
vector<int> adj[N];
vector<int> adj_scc[N];
vector<int> pp[N];
int res[N], cnt[N], tony[N];

int fpar(int u) {
    if (par[u] == u) return u;
    return par[u] = fpar(par[u]);
}

void merge(int u, int v) {
    int pu = fpar(u), pv = fpar(v);
    if (pu == pv) return;
    par[pv] = pu;
}

void tarjan(int u) {
    tin[u] = low[u] = ++timer;
    st.emplace(u); onStack[u] = true;
    for (auto v : adj[u]) {
        if (tin[v] == 0) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v]) {
            low[u] = min(low[u], tin[v]);
        }
    }
    if (tin[u] != low[u]) return;
    int w = 0; numComponent++;
    do {
        w = st.top(); st.pop();
        onStack[w] = 0;
        comp[w] = numComponent;
        cnt[numComponent]++;
    } while (w != u && !st.empty());
}

void SCC() {
    for (int i = 1; i <= n; i++) {
        if (tin[i]) continue;
        tarjan(i);
    }
}

void processLCA(int u, int p) {
    up[u][0] = p; tin[u] = ++timer;
    for (int i = 1; i < L; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (auto v : adj_scc[u]) {
        if (v == p) continue;
        processLCA(v, u);
    }
    low[u] = ++timer;
}

bool is_anc(int u, int v) {
    return (tin[u] <= tin[v] && low[u] >= low[v]);
}

int LCA(int u, int v) {
    if (is_anc(u, v)) return u;
    if (is_anc(v, u)) return v;
    for (int i = L - 1; i >= 0; i--) {
        if (!is_anc(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

void buildLCA(int u) {
    timer = 0;
    processLCA(u, u);
}

void tonyDS(int l, int r, int add) {
    debug() << imie(l) imie(r) imie(add);
    tony[l] += add;
    tony[r + 1] -= add;
}

void addAnswer(int x) {
    queue<pair<int, int>> q;
    int root = -1;
    for (int u : pp[x]) {
        if (deg[u] == 0) {
            q.emplace(u, 0);
            root = u;
        }
    }
    int maksi = 0;
    unordered_map<int, int> mp;
    while (!q.empty()) {
        auto e = q.front(); q.pop();
        int u = e.first, dist = e.second;
        maksi = max(maksi, dist);
        mp[u] = dist;
        for (int v : adj_scc[u]) {
            if (--deg[v] == 0) {
                q.emplace(v, dist + 1);
            } 
        }
    }

    buildLCA(root);

    vector<vector<int>> leaves(maksi + 1);
    unordered_map<int, int> par;
    function<void(int)> dfs = [&](int u) {
        if (adj_scc[u].empty()) {
            leaves[mp[u]].emplace_back(u);
            return;
        }
        for (int v : adj_scc[u]) {
            par[v] = u;
            dfs(v);
        }
    };

    dfs(root);

    map<pair<int, int>, bool> ok;
    for (int depth = 1; depth <= maksi; depth++) {
        int len = leaves[depth].size();
        tonyDS(1, depth, -len);
        for (int i = 0; i < len - 1; i++) {
            int u = leaves[depth][i], v = leaves[depth][i + 1];
            int w = LCA(u, v);
            int curdist = mp[w];
            if (ok[make_pair(w, depth)] == 0) {
                ok[make_pair(w, depth)] = 1;
                if (ok[make_pair(par[w], depth - 1)] == 1) {
                    tonyDS(depth - mp[par[w]], depth - 1, 1);
                }
            }
            debug() << imie(u) imie(v) imie(w) imie(depth) imie(curdist) imie(depth - curdist + 1);
            tonyDS(depth - curdist + 1, depth, 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<pair<int, int>> edges;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        edges.emplace_back(i, x);
        adj[i].emplace_back(x);
        par[i] = i;
    }
    SCC();
    for (int i = 1; i <= n; i++) {
        debug() << imie(i) imie(comp[i]) imie(cnt[comp[i]]);
    }
    for (int i = 0; i < (int) edges.size(); i++) {
        int u = edges[i].first, v = edges[i].second;
        if (comp[u] == comp[v]) continue;
        merge(comp[u], comp[v]);
        adj_scc[comp[v]].emplace_back(comp[u]);
        deg[comp[u]]++;
    }
    for (int i = 1; i <= numComponent; i++) {
        int parent = fpar(i);
        pp[parent].emplace_back(i);
    }
    for (int i = 1; i <= numComponent; i++) {
        if (pp[i].empty()) continue;
        addAnswer(i);
    }
    vector<int> ans(n + 5, -1);
    int cursz = n;
    for (int i = 1; i <= n; i++) {
        tony[i] += tony[i - 1];
        cursz += tony[i];
        if (ans[cursz] == -1) ans[cursz] = i;
        debug() << imie(i) imie(tony[i]);
    }
    int tc;
    cin >> tc;
    while (tc--) {
        int k; cin >> k;
        cout << ans[k] << '\n';
    }

    return 0;
}