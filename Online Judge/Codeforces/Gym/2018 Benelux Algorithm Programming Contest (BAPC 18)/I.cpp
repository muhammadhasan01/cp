#include <bits/stdc++.h>

using namespace std;

/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void in(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void out(T n, char CC) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar(CC);
}
/** END OF DESPERATE OPTIMIZATION **/

/** START OF TEMPLATE DEBUGGER **/
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
/** END OF TEMPLATE DEBUGGER **/

using pli = pair<long long, int>;

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
    int n, m, s;
    in(n), in(m), in(s);
    vector<int> pop(n);
    long long tot_pop = 0;
    for (int i = 0; i < n; i++) {
        in(pop[i]);
        tot_pop += (1LL) * pop[i];
    }
    debug() << imie(tot_pop);
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        in(u), in(v), in(w);
        --u, --v;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    vector<pair<int, int>> shelter(s);
    for (int i = 0; i < s; i++) {
        int u, p; in(u), in(p);
        shelter[i] = make_pair(u - 1, p);
    }
    debug() << imie(shelter);
    auto dijsktra = [&](int u) -> vector<long long> {
        vector<long long> dist(n, INF);
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        dist[u] = 0;
        pq.emplace(dist[u], u);
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int u = cur.second;
            if (dist[u] != cur.first)
                continue;
            for (const auto& e : adj[u]) {
                int v = e.first;
                long long w = e.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        return dist;
    };
    vector<vector<long long>> distances(s);
    for (int i = 0; i < s; i++) {
        distances[i] = dijsktra(shelter[i].first);
        debug() << imie(i) imie(shelter[i].first) imie(distances[i]);
    }
    int nodes = 2 + s + (1 << s);
    int source = nodes - 2, sink = nodes - 1;
    auto can = [&](long long x) -> bool {
        Dinic dinic(nodes, source, sink);
        for (int i = 0; i < s; i++) {
            dinic.add_edge(source, i, shelter[i].second);
        }
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < (1 << s); j++) {
                if ((j >> i) & 1) {
                    dinic.add_edge(i, s + j, INF);
                }
            }
        }
        vector<long long> sums((1 << s), 0LL);
        for (int i = 0; i < n; i++) {
            int k = 0;
            for (int j = 0; j < s; j++) {
                if (distances[j][i] > x) continue;
                k |= (1 << j);
            }
            sums[k] += pop[i];
        }
        for (int i = 0; i < (1 << s); i++)
            dinic.add_edge(s + i, sink, sums[i]);
        return (dinic.flow() >= tot_pop);
    };
    long long l = 0, r = INF, ans = INF;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        debug() << imie(l) << imie(r) << imie(mid);
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    out(ans, '\n');
    return 0;
}