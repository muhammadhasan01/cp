// TLE on TC 42
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 55;
const int INF = 1e9;
 
struct Edge {
    int from, to;
    int capacity, cost;
    Edge(int from, int to, int cap, int cost) : 
    from(from), to(to), capacity(cap), cost(cost) { }
};
 
vector<vector<int>> adj;
vector<vector<int>> cost, capacity;
 
void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.emplace(v0);
    p.assign(n, -1);
 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.emplace(v);
                }
            }
        }
    }
}
 
int min_cost_flow(int N, const vector<Edge>& edges, int K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    for (Edge e : edges) {
        adj[e.from].emplace_back(e.to);
        adj[e.to].emplace_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }
 
    int flow = 0;
    int cost = 0;
    vector<int> d;
    vector<int> p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;
 
        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }
 
        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }
 
    return cost;
}
 
int len[2];
vector<int> g[2][N];
int sz[2][N][N];
int dp[N][N][N][N];
 
void dfs(int tp, int u, int p) {
    sz[tp][u][p] = 1;
    for (auto v : g[tp][u]) {
        if (v == p) continue;
        dfs(tp, v, u);
        sz[tp][u][p] += sz[tp][v][u];
    }
}
 
int answer(int u, int pu, int v, int pv) {
    int& res = dp[u][pu][v][pv];
    if (res != -1) return res;
    vector<int> vx(2);
    vx[0] = g[0][u].size(), vx[1] = g[1][v].size();
    int k = max(vx[0], vx[1]);
    vector<vector<int>> cost(k, vector<int>(k));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            int cu = (i < vx[0] ? g[0][u][i] : -1);
            int cv = (j < vx[1] ? g[1][v][j] : -1);
            if (cu == pu || cv == pv) {
                cost[i][j] = -1;
            } else if (cu == -1) {
                cost[i][j] = sz[1][cv][v];
            } else if (cv == -1) {
                cost[i][j] = sz[0][cu][u];
            } else {
                cost[i][j] = answer(cu, u, cv, v);
            }
        }
    }
    vector<Edge> edges;
    int nodes = 2 * k + 2;
    int source = nodes - 2, sink = nodes - 1;
    for (int i = 0; i < k; i++)
        edges.emplace_back(source, i, 1, 0);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (cost[i][j] == -1) continue;
            edges.emplace_back(i, j + k, 1, cost[i][j]);
        }
    }
    for (int j = 0; j < k; j++)
        edges.emplace_back(j + k, sink, 1, 0);
    res = min_cost_flow(nodes, edges, INF, source, sink);
    return res;
}
 
int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    for (int it = 0; it < 2; it++) {
        cin >> len[it];
    }
    for (int it = 0; it < 2; it++) {
        for (int i = 1; i < len[it]; i++) {
            int u, v;
            cin >> u >> v; --u, --v;
            g[it][u].emplace_back(v);
            g[it][v].emplace_back(u);
        }
        for (int u = 0; u < len[it]; u++)
            dfs(it, u, u);
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < len[0]; i++) {
        for (int j = 0; j < len[1]; j++) {
            cout << answer(i, i, j, j) << (j == len[1] - 1 ? '\n' : ' ');
        }
    }
 
    return 0;
}