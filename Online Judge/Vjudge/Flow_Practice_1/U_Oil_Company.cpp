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

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve() {
    int W, H;
    cin >> H >> W;
    vector<vector<int>> r(W, vector<int>(H));
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            cin >> r[i][j];
        }
    }
    int nodes = W * H + 2;
    int source = nodes - 2, sink = nodes - 1;
    Dinic dinic(nodes, source, sink);
    int total = 0;
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            int cur = i * H + j;
            total += r[i][j];
            if ((i + j) % 2 == 0) {
                dinic.add_edge(source, cur, r[i][j]);
                for (int k = 0; k < 4; k++) {
                    int ci = i + dx[k];
                    int cj = j + dy[k];
                    if (ci < 0 || cj < 0 || ci >= W || cj >= H)
                        continue;
                    int nxt = ci * H + cj;
                    dinic.add_edge(cur, nxt, INF);
                }
            } else {
                dinic.add_edge(cur, sink, r[i][j]);
            }
        }
    }
    int answer = total - dinic.flow();
    cout << answer << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": ";
        solve();
    }

    return 0;
}