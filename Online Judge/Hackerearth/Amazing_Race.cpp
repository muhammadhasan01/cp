#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

struct point {
    long long x, y, s;
};

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
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

    void add_edge(int v, int u, long long cap) {
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

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int) adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.emplace(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
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

    int n, m, k;
    cin >> n >> m >> k;
    vector<point> teams(n);
    for (int i = 0; i < n; i++) {
        cin >> teams[i].x >> teams[i].y;
    }
    vector<point> ckpoints(m);
    for (int i = 0; i < m; i++) {
        cin >> ckpoints[i].x >> ckpoints[i].y;
    }
    for (int i = 0; i < n; i++) {
        cin >> teams[i].s;
    }
    auto timeNeeded = [&](const point& a, const point& b) {
        long long dx = a.x - b.x;
        dx = dx * dx;
        long long dy = a.y - b.y;
        dy = dy * dy;
        long long ds = a.s * a.s;
        return (dx + dy + ds - 1) / ds;
    };
    vector<vector<long long>> dist(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = timeNeeded(teams[i], ckpoints[j]);
        }
    }
    int nodes = n + m + 2;
    int source = nodes - 2, sink = nodes - 1;
    auto can = [&](long long x) {
        Dinic dinic(nodes, source, sink);
        for (int i = 0; i < n; i++)
            dinic.add_edge(source, i, 1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (dist[i][j] <= x)
                    dinic.add_edge(i, j + n, 1);
        for (int j = 0; j < m; j++)
            dinic.add_edge(j + n, sink, 1);
        return (dinic.flow() >= k);
    };
    long long l = 0, r = INF, ans = INF;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';

    return 0;
}