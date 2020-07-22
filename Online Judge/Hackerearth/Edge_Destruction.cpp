#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 1e3 + 5;
const int M = 4e5 + 5;
const int INF = 1e9 + 100;

struct FlowEdge {
    int v, u;
    int cap, flow = 0;
    FlowEdge(int v, int u, int cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const int flow_inf = INF;
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

int n, m;
pii edges[M];
vector<pii> adj[N];
bool vis[N];
int dist[N][2];

void dijkstra(int s, int it) {
    for (int i = 1; i <= n; i++)
        dist[i][it] = INF;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s][it] = 0;
    pq.emplace(dist[s][it], s);
    while (!pq.empty()) {
        auto temp = pq.top();
        pq.pop();
        int d = temp.first, u = temp.second;
        if (dist[u][it] != d) continue;
        for (auto& e : adj[u]) {
            int v = e.first;
            int w = edges[e.second].first;
            if (dist[v][it] > dist[u][it] + w) {
                dist[v][it] = dist[u][it] + w;
                pq.emplace(dist[v][it], v);
            }
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w, d;
        cin >> u >> v >> w >> d;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
        edges[i] = make_pair(w, d);
    }
    dijkstra(1, 0);
    dijkstra(n, 1);
    int distance = dist[n][0];
    Dinic dinic(n + 1, 1, n);
    queue<int> q;
    q.emplace(1); vis[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& e : adj[u]) {
            int v = e.first;
            auto& cur = edges[e.second];
            if (dist[u][0] + cur.first + dist[v][1] == distance)
                dinic.add_edge(u, v, cur.second);
            if (vis[v]) continue;
            vis[v] = 1;
            q.emplace(v);
        }
    }
    cout << dinic.flow() << '\n';

    return 0;
}