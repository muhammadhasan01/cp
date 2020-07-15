#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;
const int INF = 2e9;

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
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
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
                q.push(edges[id].u);
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
            q.push(s);
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

int n, E, X;
int mat[N][N];
int pop[N], pod[N];
int total_people;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> E >> X;
    for (int i = 1; i <= n; i++) {
        cin >> pop[i];
        total_people += pop[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> pod[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mat[i][j] = (i == j ? 0 : INF);
        }
    }
    for (int i = 1; i <= E; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        mat[u][v] = mat[v][u] = t;
    }
    // Floyd Warshall to find closest distances
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (mat[i][k] == INF) continue;
                if (mat[k][j] == INF) continue;
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
    // Consider 2xN vertices, 0 - (N-1) city_ppl and N - (2N-1) city_pods
    // 2N and 2N+1 are source and sink
    int nodes = 2 * n + 2, source = 2 * n, sink = 2 * n + 1;
    Dinic dinic(nodes, source, sink);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mat[i][j] <= X) {
                // Add an edge from ppl i to pod j
                dinic.add_edge(i - 1, j - 1 + n, INF);
            }
        }
    }
    // Now, add a new source/sink such that 
    // source->city_ppl = population and city_pods->sink = #pods
    for (int i = 1; i <= n; i++) {
        dinic.add_edge(source, i - 1, pop[i]);
        dinic.add_edge(i + n - 1, sink, pod[i]);
    }
    total_people -= dinic.flow();
    cout << total_people << '\n';

    return 0;
}