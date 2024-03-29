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

vector<vector<pair<int, int>>> adj;
unordered_map<int, int> capacity[NMAX];
vector<Edge> edges;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p, int t) {
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
        for (auto& e : adj[u]) {
            int v = e.first;
            int cst = e.second;
            if (capacity[u][v] > 0 && d[v] > d[u] + cst) {
                d[v] = d[u] + cst;
                p[v] = u;
                q.emplace(d[v], v);
            }
        }
    }
}

int min_cost_flow(int N, int K, int s, int t) {
    adj.assign(N, vector<pair<int, int>>());
    for (Edge e : edges) {
        adj[e.from].emplace_back(e.to, e.cost);
        adj[e.to].emplace_back(e.from, -e.cost);
        capacity[e.from][e.to] = e.capacity;
    }

    int flow = 0;
    int cost = 0;
    vector<int> d;
    vector<int> p;
    while (flow < K) {
        shortest_paths(N, s, d, p, t);
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

const int N = 5e3 + 5;

int n;
int a[N];

int main() {
    int n;
    inpos(n);
    for (int i = 1; i <= n; i++) {
        inpos(a[i]);
    }
    int nodes = 2 * n + 3;
    int source = nodes - 2, sink = nodes - 1;
    edges.emplace_back(source, 0, 2, 0);
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
    int ans = -min_cost_flow(nodes, INF, source, sink);
    outpos(ans);

    return 0;
}