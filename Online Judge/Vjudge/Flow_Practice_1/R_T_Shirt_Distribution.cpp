#include <bits/stdc++.h>

using namespace std;

const int INF = 1e18;

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

    const int N = 6;
    const vector<string> sizes = {"S", "M", "L", "XL", "XXL", "XXXL"};
    map<string, int> mp;
    for (int i = 0; i < N; i++) {
        mp[sizes[i]] = i;
    }
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    int n;
    cin >> n;
    int nodes = N + n + 2;
    int source = nodes - 2, sink = nodes - 1;
    Dinic dinic(nodes, source, sink);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s; s += ",";
        string cur = "";
        for (int j = 0; j < (int) s.size(); j++) {
            if (s[j] == ',') {
                int id = mp[cur];
                dinic.add_edge(i, id + n, 1);
                cur = "";
            } else {
                cur += s[j];
            }
        }
        dinic.add_edge(source, i, 1);
    }
    for (int i = 0; i < N; i++) {
        dinic.add_edge(i + n, sink, nums[i]);
    }
    int flow = dinic.flow();
    if (flow != n) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    vector<FlowEdge>& e = dinic.edges;
    vector<string> ans(n);
    for (int i = 0; i < (int) e.size(); i += 2) {
        if (e[i].v == source || e[i].u == sink) continue;
        if (!e[i].flow) continue;
        ans[e[i].v] = sizes[e[i].u - n];
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}