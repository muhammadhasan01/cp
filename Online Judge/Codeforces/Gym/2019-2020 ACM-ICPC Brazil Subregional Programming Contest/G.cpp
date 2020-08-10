#include <bits/stdc++.h>

using namespace std;

const double INF = 1e9;

struct Edge {
    int from, to;
    double capacity, cost;
    Edge(int from, int to, double cap, double cost) : 
    from(from), to(to), capacity(cap), cost(cost) { }
};

vector<vector<int>> adj;
vector<vector<double>> cost, capacity;

void shortest_paths(int n, int v0, vector<double>& d, vector<int>& p) {
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

void min_cost_flow(int N, const vector<Edge>& edges, double K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<double>(N, 0));
    capacity.assign(N, vector<double>(N, 0));
    for (Edge e : edges) {
        adj[e.from].emplace_back(e.to);
        adj[e.to].emplace_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    double flow = 0;
    double cost = 0;
    vector<double> d;
    vector<int> p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;

        // find max flow on that path
        double f = K - flow;
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
    int n = N / 2 - 1;
    vector<int> ans(n);
    int cnt = 0;
    for (auto& e : edges) {
        if (e.from == s || e.to == t) continue;
        if (capacity[e.from][e.to] == 0) {
            ans[e.to - n] = ++cnt;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? '\n' : ' ');
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int nodes = 2 * n + 2;
    int source = nodes - 2, sink = nodes - 1;
    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        edges.emplace_back(source, i, 1, 0);
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            double val = log2(x);
            edges.emplace_back(i, j + n, 1, -val);
        }
        edges.emplace_back(i + n, sink, 1, 0);
    }
    min_cost_flow(nodes, edges, INF, source, sink);

    return 0;
}