#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, n, k;
    cin >> m >> n >> k;
    int nodes = n + m + 2;
    int source = nodes - 2, sink = nodes - 1;
    Dinic dinic(nodes, source, sink);
    for (int i = 0; i < m; i++) {
        dinic.add_edge(source, i, 1);
    }
    vector<vector<int>> CS(m), CE(n);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        CS[x].emplace_back(y);
        CE[y].emplace_back(x);
        dinic.add_edge(x, y + m, 1);
    }
    for (int i = 0; i < n; i++) {
        dinic.add_edge(i + m, sink, 1);
    }
    int flow = dinic.flow();
    vector<int> elc(n, -1), sock(m, -1);
    for (auto& e : dinic.edges) {
        int u = e.v, v = e.u;
        int f = e.flow;
        if (u < m && m <= v && v < n + m && f == 1) {
            sock[u] = v - m;
            elc[v - m] = u;
        }
    }
    vector<int> ans_sock(m);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        if (elc[i] != -1) continue;
        vector<bool> vis_sock(m), vis_elc(n);
        queue<pair<int, int>> q;
        vis_elc[i] = 1;
        for (int x : CE[i]) {
            vis_sock[x] = 1;
            q.emplace(x, 1);
        }
        while (!q.empty()) {
            int x, tp;
            tie(x, tp) = q.front();
            q.pop();
            if (tp == 1) {
                int y = sock[x];
                if (y == -1 || vis_elc[y]) continue;
                vis_elc[y] = 1;
                q.emplace(y, 0);
            } else {
                for (int y : CE[x]) {
                    if (vis_sock[y]) continue;
                    vis_sock[y] = 1;
                    q.emplace(y, 1);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (vis_sock[i]) ans_sock[i]++;
        }
    }
    int ans = flow;
    for (int i = 0; i < m; i++) {
        int cur = ans_sock[i];
        int mini = (sock[i] == -1 ? 3 : 2);
        cur = min(cur, mini);
        ans = max(ans, flow + cur);
    }
    cout << ans << '\n';

    return 0;
}