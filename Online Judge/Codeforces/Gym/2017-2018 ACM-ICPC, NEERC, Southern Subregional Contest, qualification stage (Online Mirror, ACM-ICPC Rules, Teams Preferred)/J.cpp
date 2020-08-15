#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

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

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        mp[{u, v}]++;
    }
    int len = mp.size();
    int nodes = n + len + 2, source = 0, sink = nodes - 1;
    Dinic dinic(nodes, source, sink);
    for (int i = 1; i <= n; i++)
        dinic.add_edge(source, i, 1);
    int cnt = 1;
    vector<pair<int, int>> pm;
    for (auto& e : mp) {
        pair<int, int> cur = e.first;
        pm.emplace_back(cur);
        int u = cur.first, v = cur.second;
        int w = n + cnt;
        dinic.add_edge(u, w, 1);
        dinic.add_edge(v, w, 1);
        dinic.add_edge(w, sink, 1);
        ++cnt;
    }
    function<bool(int)> can = [&] (int x) {
        Dinic curdinic = dinic;
        for (int i = 0; i < n; i++) {
            curdinic.edges[2 * i].cap = x;
        }
        return curdinic.flow() >= m;
    };
    int l = 0, r = n, at = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            at = mid;
        } else {
            l = mid + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        dinic.edges[2 * i].cap = at;
    }
    dinic.flow();
    vector<pair<int, int>> ans;
    for (int i = n; 2 * i < (int) dinic.edges.size(); i++) {
        FlowEdge& edge = dinic.edges[2 * i];
        if (edge.u == sink || edge.flow == 0) continue;
        int u = edge.v, v = edge.u - n - 1;
        int w = pm[v].first;
        if (u == w) w = pm[v].second;
        ans.emplace_back(u, w);
    }
    cout << at << '\n';
    for (auto& e : ans) {
        cout << e.first << ' ' << e.second << '\n';
    }

    return 0;
}