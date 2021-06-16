#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = INF;
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

const int N = 25;
const int M = N * N * N * N + 1000;
const int dx[] = {1, 0, 1};
const int dy[] = {0, 1, 1};

int n, m;
int a[N][N];
int island[N][N];
pair<int, int> coord[N * N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    int source = 0, sink = M - 1;
    Dinic dinic(M, source, sink);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 0) continue;
            island[i][j] = ++cnt;
            coord[cnt] = make_pair(i, j);
            dinic.add_edge(source, island[i][j], 1);
        }
    }
    map<tuple<int, int, int, int>, int> mp;
    set<pair<int, int>> st;

    auto add_edge_unique = [&](int x, int y) -> void {
        pair<int, int> cur = make_pair(x, y);
        if (st.find(cur) == st.end()) {
            dinic.add_edge(x, y, 1);
            st.emplace(cur);
        }
    };

    auto check = [&](int i, int j, int val) -> void {
        for (int k = 0; k < 3; k++) {
            int ci = i + dx[k];
            int cj = j + dy[k];
            if (ci < 1 || ci > n || cj < 1 || cj > m) {
                continue;
            }
            if (a[ci][cj] == 1) {
                auto cur = make_tuple(min(i, ci), min(j, cj), max(i, ci), max(j, cj));
                if (!mp.count(cur)) {
                    mp[cur] = ++cnt;
                    dinic.add_edge(cnt, sink, 1);
                }
                add_edge_unique(island[i][j], val);
                add_edge_unique(island[i][j], mp[cur]);
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 0) continue;
            for (int k = 0; k < 3; k++) {
                int ci = i + dx[k];
                int cj = j + dy[k];
                if (ci < 1 || ci > n || cj < 1 || cj > m) {
                    continue;
                }
                if (a[ci][cj] == 1) {
                    auto cur = make_tuple(min(i, ci), min(j, cj), max(i, ci), max(j, cj));
                    if (!mp.count(cur)) {
                        mp[cur] = ++cnt;
                        dinic.add_edge(cnt, sink, 1);
                    }
                    check(ci, cj, mp[cur]);
                }
            }
        }
    }
    cout << dinic.flow() << '\n';
    for (auto& edge : dinic.edges) {
        if (edge.v == source && edge.flow == 1) {
            cerr << edge.v << " => " << edge.u << " => " << edge.flow << '\n';
        }
    }

    return 0;
}