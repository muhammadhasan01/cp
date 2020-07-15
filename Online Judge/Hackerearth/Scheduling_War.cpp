#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

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
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
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
                q.push(edges[id].u);
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
            q.push(s);
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

    int n;
    cin >> n;
    vector<int> proc(n);
    for (int i = 0; i < n; i++) {
        cin >> proc[i];
    }
    int m;
    cin >> m;
    vector<int> oproc(m);
    vector<vector<int>> batch(m);
    for (int i = 0; i < m; i++) {
        int len;
        cin >> len;
        batch[i].resize(len);
        for (int j = 0; j < len; j++) {
            cin >> batch[i][j];
            batch[i][j]--;
        }
        cin >> oproc[i];
    }
    int ans = 0;
    int source = n + m + 1, sink = n + m + 2;
    Dinic dinic(n + m + 3, source, sink);
    for (int i = 0; i < m; i++) {
        dinic.add_edge(source, i, oproc[i]);
        ans += oproc[i];
        for (auto& s : batch[i]) {
            dinic.add_edge(i, s + m, INF);
        }
    }
    for (int i = 0; i < n; i++) {
        dinic.add_edge(m + i, sink, proc[i]);
    }
    ans -= dinic.flow();
    cout << ans << '\n';

    return 0;
}