#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

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

const int W = 505;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> edges(W);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[w].emplace_back(u, v);
    }
    vector<int> par(n + 1);
    iota(par.begin(), par.end(), 0);
    function<int(int)> fpar = [&](int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = fpar(par[x]);
    };
    Dinic dinic(2 * n, 0, n);
    int ans = 0;
    for (int w = 0; w < W; w++) {
        if (edges[w].empty()) {
            continue;
        }
        for (auto& [u, v] : edges[w]) {
            int pu = fpar(u), pv = fpar(v);
            if (pu == pv) {
                Dinic cur = dinic;
                cur.s = u;
                cur.t = v;
                ans += cur.flow();
            }
        }
        for (auto& [u, v] : edges[w]) {
            dinic.add_edge(u, v, 1);
            dinic.add_edge(v, u, 1);
            int pu = fpar(u), pv = fpar(v);
            par[pu] = pv;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}