#include <bits/stdc++.h>

using namespace std;

const int INF = 1e3;

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

const int K = 4;
const int DX[] = {0, 0, 1, -1};
const int DY[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int r, c, d;
    cin >> r >> c >> d;
    vector<vector<char>> a(r + 1, vector<char>(c + 1));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> a[i][j];
        }
    }
    int area = r * c;
    int nodes = 2 * area + 2;
    int source = 0, sink = nodes - 1;
    Dinic dinic(nodes, source, sink);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            int id = c * (i - 1) + j;
            if (a[i][j] == 'S') {
                dinic.add_edge(source, id, 1);
            } else if (a[i][j] == 'P') {
                dinic.add_edge(id, sink, 1);
            }
            if (a[i][j] != 'H') {
                continue;
            }
            dinic.add_edge(id, id + area, 1);
            queue<tuple<int, int, int>> q;
            q.emplace(i, j, 0);
            set<pair<int, int>> vis;
            vis.emplace(i, j);
            set<int> schools, parks;
            while (!q.empty()) {
                auto [x, y, dist] = q.front();
                q.pop();
                for (int dir = 0; dir < K; dir++) {
                    int cx = x + DX[dir];
                    int cy = y + DY[dir];
                    if (cx < 1 || cy < 1 || cx > r || cy > c) {
                        continue;
                    }
                    if (vis.count({cx, cy})) {
                        continue;
                    }
                    vis.emplace(cx, cy);
                    if (a[cx][cy] == '.') {
                        q.emplace(cx, cy, dist + 1);
                        continue;
                    }
                    int cid = c * (cx - 1) + cy;
                    if (a[cx][cy] == 'S' && dist + 1 <= d) {
                        schools.emplace(cid);
                    } else if (a[cx][cy] == 'P' && dist + 1 <= d) {
                        parks.emplace(cid);
                    }
                }
            }
            for (int sid : schools) {
                dinic.add_edge(sid, id, 1);
            }
            for (int pid : parks) {
                dinic.add_edge(id + area, pid, 1);
            }
        }
    }
    cout << dinic.flow() << '\n';
    
    return 0;
}