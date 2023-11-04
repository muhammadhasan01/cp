#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;
const int INFF = 1e9;
struct FlowEdge {
    int v, u;
    int cap, flow = 0;
    FlowEdge(int v, int u, int cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const int flow_inf = 1e18;
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
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
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
int32_t main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n, m, d;
        cin >> n >> m >> d;
        int nodes = 2000, source = 0, sink = nodes - 1;
        Dinic D(nodes, source, sink);
        vector<vector<char>> v(n + 5, vector<char>(m + 5, '#'));
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> v[i][j];
        vector<pair<int, int>> house;
        vector<pair<int, int>> park;
        vector<pair<int, int>> school;
        int tim = 0;
        map<pair<int, int>, int> id;
        for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                        if (v[i][j] == 'H') {
                                house.push_back({i, j});
                                id[{i, j}] = ++tim;
                        }
                        if (v[i][j] == 'S') {
                                school.push_back({i, j});
                                id[{i, j}] = ++tim;
                                id[{-i, -j}] = ++tim;
                        } 
                        if (v[i][j] == 'P') {
                                park.push_back({i, j});
                                id[{i, j}] = ++tim;
                        }
                }
        }
        for (auto [a, b] : school) D.add_edge(id[{a, b}], id[{-a, -b}], 1);
        for (auto [c, d] : park) D.add_edge(id[{c, d}], sink, 1);
        for (auto [x, y] : house) D.add_edge(source, id[{x, y}], 1);
        vector<vector<int>> dist(n + 5, vector<int>(m + 5, INFF));
        auto bfs = [&](int x, int y) {
                for (int i = 1; i <= n; i++) {
                        for (int j = 1; j <= m; j++) {
                                dist[i][j] = INFF;
                        }
                }
                queue<pair<int, int>> q;
                q.push({x, y});
                dist[x][y] = 0;
                int dx[] = {1, 0, -1, 0};
                int dy[] = {0, 1, 0, -1};
                while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                                int cx = x + dx[k];
                                int cy = y + dy[k];
                                if (v[cx][cy] != '#' && dist[cx][cy] == INFF) {
                                        dist[cx][cy] = dist[x][y] + 1;
                                        if (v[cx][cy] == '.') q.push({cx, cy});
                                }
                        }
                }
                for (auto [a, b] : school) {
                        if (dist[a][b] > d) continue;
                        D.add_edge(id[{x, y}], id[{a, b}], 1);
                        for (auto [c, dd] : park) {
                                if (dist[c][dd] > d) continue;
                                D.add_edge(id[{-a, -b}], id[{c, dd}], 1);
                        }
                }
        };
        for (auto [x, y] : house) bfs(x, y);
        cout << D.flow() << '\n';
        return 0;
}