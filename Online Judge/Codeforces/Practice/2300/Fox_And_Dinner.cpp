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

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto dismiss = [&]() -> void {
        puts("Impossible");
        exit(0);
    };

    if (n % 2 == 1) {
        dismiss();
    }

    auto isPrime = [&](int x) -> bool {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    };

    const int nodes = n + 2;
    const int source = nodes - 2, sink = nodes - 1;
    Dinic dinic(nodes, source, sink);
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            dinic.add_edge(source, i, 2);
        else
            dinic.add_edge(i, sink, 2);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int val = a[i] + a[j];
            if (isPrime(val)) {
                int u = i, v = j;
                if (a[u] % 2 == 1) swap(u, v);
                dinic.add_edge(u, v, 1);
            }
        }
    }
    int flow = dinic.flow();
    vector<vector<int>> adj(n);
    for (auto& e : dinic.edges) {
        int u = e.v, v = e.u;
        if (u == sink || u == source) continue;
        if (v == sink || v == source) continue;
        if (a[u] % 2 == 1) continue;
        if (e.flow == 0) continue;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    if (flow != n) dismiss();
    vector<vector<int>> answer;
    vector<bool> vis(n);

    function<void(int, vector<int>&)> dfs = [&](int u, vector<int>& cur) {
        vis[u] = 1;
        cur.emplace_back(u + 1);
        for (int v : adj[u]) {
            if (vis[v]) continue;
            dfs(v, cur);
        }
    };
    
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vector<int> cur;
        dfs(i, cur);
        answer.emplace_back(cur);
    }
    cout << answer.size() << '\n';
    for (auto& e : answer) {
        int len = e.size();
        cout << len << ' ';
        for (int i = 0; i < len; i++) {
            cout << e[i] << (i == len - 1 ? '\n' : ' ');
        }
    }

    return 0;
}