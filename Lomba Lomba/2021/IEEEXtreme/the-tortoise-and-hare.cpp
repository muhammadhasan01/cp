#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

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

const ll INF = 1e18;
const int N = 3e5 + 5;
const int B = 8;

int n, m, s, t;
vector<pair<int, int>> adj[N];
vector<pair<int, int>> sht[N];

int tin[N], low[N], timer = 0;
bool visited[N];
bool is_cutpoint[N];
bool art[N];
int par[N];
bool marked[N];
 
void dfs(int u, int p = -1) {
    visited[u] = true;
    tin[u] = low[u] = timer++;
    int children = 0;
    for (auto [v, w] : sht[u]) {
        if (v == p) {
            continue;
        }
        if (visited[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            par[v] = u;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (tin[u] <= low[v] && p != -1) {
                is_cutpoint[u] = true;;
            }
            ++children;
        }
    }
    if (p == -1 && children > 1) {
        is_cutpoint[u] = true;
    }
}

vector<ll> dijkstra(int st) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<ll> dist(n + 1, INF);
    dist[st] = 0;
    pq.emplace(dist[st], st);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] != d) {
            continue;
        }
        for (auto [v, w] : adj[u]) {
            if (marked[v]) {
                continue;
            }
            if (dist[v] == INF || dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
};

ll getDijkstra(int st) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<ll> dist(n + 1, INF);
    dist[st] = 0;
    pq.emplace(dist[st], st);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] != d) {
            continue;
        }
        for (auto [v, w] : adj[u]) {
            if (marked[v]) {
                continue;
            }
            if (dist[v] == INF || dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist[t];
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    in(n), in(m), in(s), in(t);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        in(u), in(v), in(w);
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    auto ds = dijkstra(s);
    auto dt = dijkstra(t);
    auto bfs = [&]() {
        queue<int> q;
        vector<bool> vis(n + 1);
        q.emplace(s);
        vis[s] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto [v, w] : adj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.emplace(v);
                }
                if (ds[u] + w + dt[v] == ds[t]) {
                    sht[u].emplace_back(v, w);
                    sht[v].emplace_back(u, w);
                }
            }
        }
    };
    bfs();
    dfs(s);
    art[s] = art[t] = true;
    vector<int> nodes;
    for (int u = t, min_low = low[u]; u != s; u = par[u]) {
        assert(par[u] > 0);
        if (is_cutpoint[u] && tin[u] <= min_low) {
            art[u] = true;
            nodes.emplace_back(u);
        }
        min_low = min(min_low, low[u]);
    }
    int ans = -1;
    for (int u = 1; u <= n; u++) {
        if (art[u]) {
            continue;
        }
        ans = u;
    }
    ll curd = ds[t];
    vector<bool> vis(n + 1);
    for (int it = 0; it < 2; it++) {
        int len = nodes.size();
        for (int i = 0; i < min(B, len); i++) {
            int u = nodes[i];
            if (vis[u]) {
                continue;
            }
            vis[u] = true;
            marked[u] = true;
            auto dist = getDijkstra(s);
            marked[u] = false;
            if (dist == INF) {
                continue;
            }
            if (dist > curd) {
                curd = dist;
                ans = u;
            }
        }
        reverse(nodes.begin(), nodes.end());
    }
    out(ans, '\n');
    
    return 0;
}