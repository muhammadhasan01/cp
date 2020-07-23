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

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> px(n), py(n);
        vector<vector<int>> val(2);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            px[i] = x, py[i] = y;
            val[0].emplace_back(x);
            val[1].emplace_back(y);
        }
        vector<int> len(2);
        for (int i = 0; i < 2; i++) {
            sort(val[i].begin(), val[i].end());
            val[i].resize(unique(val[i].begin(), val[i].end()) - val[i].begin());
            len[i] = val[i].size();
        }
        int nodes = len[0] + len[1] + 2;
        int source = nodes - 2, sink = nodes - 1;
        Dinic dinic(nodes, source, sink);
        for (int i = 0; i < len[0]; i++)
            dinic.add_edge(source, i, 1);
        for (int i = 0; i < n; i++) {
            px[i] = lower_bound(val[0].begin(), val[0].end(), px[i]) - val[0].begin();
            py[i] = lower_bound(val[1].begin(), val[1].end(), py[i]) - val[1].begin();
            dinic.add_edge(px[i], py[i] + len[0], 1);   
        }
        for (int j = 0; j < len[1]; j++)
            dinic.add_edge(j + len[0], sink, 1);
        cout << dinic.flow() << '\n';
    }

    return 0;
}