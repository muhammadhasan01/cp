#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int from, to;
    long long capacity, cost;
    Edge(int from, int to, long long cap, long long cost) : 
    from(from), to(to), capacity(cap), cost(cost) { }
};

vector<vector<int>> adj;
vector<vector<long long>> cost, capacity;

void shortest_paths(int n, int v0, vector<long long>& d, vector<int>& p) {
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
    vector<long long> d;
    vector<int> p;
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

    if (flow < K) return -1;
    return cost;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> nums;
    vector<map<int, int>> dice(n);
    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;
        for (int j = 0; j < len; j++) {
            int u, cost;
            cin >> u >> cost;
            dice[i][u] = cost;
        }
    }
    int m;
    cin >> m;
    int nodes = 2 * n + 2;
    int source = nodes - 2, sink = nodes - 1;
    for (int i = 0; i < m; i++) {
        vector<Edge> edges;
        for (int j = 0; j < n; j++)
            edges.emplace_back(source, j, 1, 0);
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            for (int k = 0; k < n; k++)
                if (dice[k].count(x))
                    edges.emplace_back(k, j + n, 1, dice[k][x]);
        }
        for (int j = 0; j < n; j++)
            edges.emplace_back(j + n, sink, 1, 0);
        cout << min_cost_flow(nodes, edges, n, source, sink) << '\n';
    }

    return 0;
}