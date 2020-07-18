#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 5;
const long long INF = 1e18;

struct Edge
{
    int from, to;
    long long capacity, cost;
    Edge(int from, int to, long long cap, long long cost) : 
    from(from), to(to), capacity(cap), cost(cost) { }
};

int n, m;
long long a[N], dp[N][N];
vector<vector<int>> adj;
vector<vector<long long>> cost, capacity;
vector<Edge> edges;

void shortest_paths(int n, int v0, vector<long long>& d, vector<long long>& p) {
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

long long min_cost_flow(int N, const vector<Edge>& edges, long long K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<long long>(N, 0));
    capacity.assign(N, vector<long long>(N, 0));
    for (Edge e : edges) {
        adj[e.from].emplace_back(e.to);
        adj[e.to].emplace_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    long long flow = 0;
    long long cost = 0;
    vector<long long> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;

        // find max flow on that path
        long long f = K - flow;
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

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (i == j ? 0LL : INF);
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        dp[u][v] = min(dp[u][v], w);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][k] == INF || dp[k][j] == INF) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);  
            }
        }
    }
    int nodes = n + n + 2;
    int source = n + n, sink = n + n + 1;
    for (int i = 0; i < n; i++) {
        edges.emplace_back(source, i, 1, 0);
        edges.emplace_back(i + n, sink, 1, 0);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                edges.emplace_back(i, j + n, 1, a[i + 1]);
            } else {
                edges.emplace_back(i, j + n, 1, dp[i + 1][j + 1]);
            }
        }
    }
    cout << min_cost_flow(nodes, edges, INF, source, sink) << '\n';

    return 0;
}