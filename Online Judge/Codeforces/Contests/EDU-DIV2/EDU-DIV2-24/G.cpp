#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void inpos(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void outpos(T n) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar('\n');
}

const int INF = 1e9;
const int NMAX = 1e4 + 200;

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
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.emplace(d[v0], v0);
    p.assign(n, -1);

    while (!q.empty()) {
        auto cur = q.top();
        q.pop();
        int dist = cur.first, u = cur.second;
        if (dist != d[u]) continue;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                q.emplace(d[v], v);
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

const int N = 3e3 + 5;

int n;
int a[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    inpos(n);
    for (int i = 1; i <= n; i++) {
        inpos(a[i]);
    }
    vector<Edge> edges;
    int nodes = 2 * n + 3;
    int source = nodes - 2, sink = nodes - 1;
    edges.emplace_back(source, 0, 4, 0);
    for (int i = 1; i <= n; i++) {
        edges.emplace_back(0, i, 1, 0);
        edges.emplace_back(i, i + n, 1, -1);
        edges.emplace_back(i + n, sink, 1, 0);
        int c1 = 3, c2 = 3, c3 = 3;
        for (int j = i + 1; j <= n; j++) {
            if (a[i] - a[j] == 1 && c1) {
                edges.emplace_back(i + n, j, 1, 0); c1--;
            } else if (a[i] - a[j] == -1 && c2) {
                edges.emplace_back(i + n, j, 1, 0); c2--;
            } else if (a[i] % 7 == a[j] % 7 && c3) {
                edges.emplace_back(i + n, j, 1, 0); c3--;
            }
        }
    }
    int ans = -min_cost_flow(nodes, edges, INF, source, sink);
    outpos(ans);

    return 0;
}