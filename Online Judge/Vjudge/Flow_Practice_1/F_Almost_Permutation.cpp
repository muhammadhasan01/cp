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

int n, q;
int low[N], high[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        low[i] = 1, high[i] = n;
    }
    while (q--) {
        int tp, l, r, x;
        cin >> tp >> l >> r >> x;
        for (int i = l; i <= r; i++) {
            if (tp == 1) {
                low[i] = max(low[i], x);
            } else {
                high[i] = min(high[i], x);
            }
        }
    }
    int nodes = N * N + 4 * N;
    int source = 0, sink = nodes - 1;
    vector<Edge> edges;
    for (int i = 1; i <= n; i++) {
        if (low[i] > high[i]) {
            cout << -1 << '\n';
            return 0;
        }
        edges.emplace_back(source, i, 1, 0);
        for (int j = 1; j <= n; j++)
            edges.emplace_back(i + n, i + 2 * n + j + (i - 1) * n - 1, 1, 0);
        for (int j = low[i]; j <= high[i]; j++)
            edges.emplace_back(i, j + n, 1, 0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            edges.emplace_back(i + 2 * n + j + (i - 1) * n - 1, sink, 1, 2 * j - 1);
        }
    }
    cout << min_cost_flow(nodes, edges, INF, source, sink) << '\n';

    return 0;
}
