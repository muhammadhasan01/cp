#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
const int INF = 1e9;

struct FlowEdge {
    int v, u;
    int cap, flow = 0;
    FlowEdge(int v, int u, int cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const int flow_inf = INF;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, int cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].emplace_back(m);
        adj[u].emplace_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.emplace(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    int dfs(int v, int pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int) adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            int tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    int flow() {
        int f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.emplace(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int tc;
int n, m;
bool vis[N];
vector<int> adj[N];
vector<int> comp[N];
int par[N], sz_edge[N];

int fpar(int x) {
    return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu == pv) return;
    par[pv] = pu;
}

void init() {
    for (int i = 1; i <= n; i++) {
        vis[i] = 0; sz_edge[i] = 0;
        par[i] = i; comp[i].clear();
        adj[i].clear();
    }
}

void dfs(int u, Dinic& dinic) {
    vis[u] = 1;
    for (auto& v : adj[u]) {
        dinic.add_edge(u, n + v, 1);
        if (vis[v]) continue;
        dfs(v, dinic);
    }
}

void solve() {
    cin >> n >> m;
    init();
    set<pair<int, int>> st;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        st.emplace(u, v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        merge(u, v);
    }
    assert((int) st.size() == m);
    for (int i = 1; i <= n; i++) {
        int parent = fpar(i);
        comp[parent].emplace_back(i);
        sz_edge[parent] += (int) adj[i].size();
    }
    for (int i = 1; i <= n; i++) {
        if (i != fpar(i)) continue;
        int nodes = 2 * n + 2, source = 0, sink = nodes - 1;
        Dinic dinic(nodes, source, sink);
        int len = comp[i].size();
        for (int j = 0; j < len; j++) {
            dinic.add_edge(source, comp[i][j], 1);
            dinic.add_edge(n + comp[i][j], sink, 3);
        }
        dfs(i, dinic);
        if (dinic.flow() < sz_edge[i] / 2) {    
            cout << "Tidak Mungkin" << '\n';
            return;
        }
    }
    cout << "Mungkin" << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}