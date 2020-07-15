#include <bits/stdc++.h>

using namespace std;

struct FlowEdge {
    int v, u;
    int cap, flow = 0;
    FlowEdge(int v, int u, int cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const int flow_inf = 2e9;
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

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<int> resRow(n), resCol(m);
        vector<int> x(n), y(m);
        vector<vector<int>> id(n, vector<int>(m));
        int nodes = n + m + 2;
        int source = nodes - 2, sink = nodes - 1;
        Dinic dinic(nodes, source, sink);
        for (int i = 0; i < n; i++) {
            int resRow;
            cin >> resRow; resRow -= m;
            x[i] = dinic.m;
            dinic.add_edge(source, i, resRow);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                id[i][j] = dinic.m;
                dinic.add_edge(i, j + n, 4);
            }
        }
        for (int i = 0; i < m; i++) {
            int resCol;
            cin >> resCol; resCol -= n;
            y[i] = dinic.m;
            dinic.add_edge(i + n, sink, resCol);
        }
        dinic.flow();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int pos = id[i][j];
                vector<FlowEdge>& edges = dinic.edges;
                int flow = edges[pos].flow;
                edges[pos].cap = edges[pos + 1].cap = 0;
                int res = 1;
                if (flow > 0) {
                    edges[x[i]].cap += flow, edges[y[j]].cap += flow;
                    int tmp = dinic.flow();
                    int rem = flow - tmp;
                    edges[x[i]].cap -= rem, edges[y[j]].cap -= rem;
                    res += rem;
                }
                cout << res << (j == m - 1 ? '\n' : ' ');
            }
        }
    }

    return 0;
}