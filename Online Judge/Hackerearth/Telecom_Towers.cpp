#include <bits/stdc++.h>

using namespace std;

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

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> triples;
    for (int i = -d; i <= d; i++) {
        for (int j = -d; j <= d; j++) {
            if (i * i + j * j != d * d) continue;
            triples.emplace_back(i, j);
        }
    }
    map<pair<int, int>, int> mp;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mp[make_pair(x, y)] = i;
        for (auto& e : triples) {
            int cx = x + e.first;
            int cy = y + e.second;
            pair<int, int> cur = make_pair(cx, cy);
            if (!mp.count(cur)) continue;
            int j = mp[cur];
            adj[i].emplace_back(j);
            adj[j].emplace_back(i);
        }
    }
    vector<int> col(n, -1);
    auto bfs = [&](int x) {
        queue<int> q;
        q.emplace(x); col[x] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : adj[u]) {
                if (col[v] == -1) {
                    col[v] = 1 - col[u];
                    q.emplace(v);
                }
            }
        }
    };
    for (int i = 0; i < n; i++)
        if (col[i] == -1)
            bfs(i);
    int nodes = n + 2, source = n, sink = n + 1;
    Dinic dinic(nodes, source, sink);
    for (int i = 0; i < n; i++) {
        if (col[i] == 0) {
            dinic.add_edge(source, i, 1);
            for (auto& j : adj[i])
                dinic.add_edge(i, j, 1);
        } else {
            dinic.add_edge(i, sink, 1);
        }
    }
    cout << dinic.flow() << '\n';
    
    return 0;
}