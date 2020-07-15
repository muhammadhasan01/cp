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

const int N = 1e3 + 5;
const int P = 2;

int n;
vector<int> v[2];
int len[P];
int cnt[P][N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int c, d;
        cin >> c >> d;
        --c;
        cnt[c][d]++;
        v[c].emplace_back(d);
    }
    for (int c = 0; c < 2; c++) {
        sort(v[c].begin(), v[c].end());
        v[c].resize(unique(v[c].begin(), v[c].end()) - v[c].begin());
        len[c] = v[c].size();
    }
    int nodes = len[0] + len[1] + 2;
    int source = len[0] + len[1];
    int sink = len[0] + len[1] + 1;
    Dinic dinic(nodes, source, sink);
    for (int i = 0; i < len[0]; i++)
        dinic.add_edge(source, i, cnt[0][v[0][i]]);
    for (int i = 0; i < len[0]; i++) {
        int mind = ceil(v[0][i] / sqrt(2.0));
        int maxd = floor(v[0][i] * sqrt(2.0));
        for (int j = 0; j < len[1]; j++) {
            if (mind <= v[1][j] && v[1][j] <= maxd)
                dinic.add_edge(i, j + len[0], cnt[0][v[0][i]]);
        }
    }
    for (int i = 0; i < len[1]; i++)
        dinic.add_edge(i + len[0], sink, cnt[1][v[1][i]]);
    cout << dinic.flow() << '\n';

    return 0;
}