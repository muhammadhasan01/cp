#include <bits/stdc++.h>

using namespace std;
using pli = pair<long long, int>;

const long long INF = 1e18;
const int N = 1e5 + 5;
const int L = 20;

int n, m, q;
int wv[N], par[N];
int up[N][L], tin[N], tout[N], tim;
bool in_mst[N], special_node[N];
long long dist[N];
vector<pair<int, int>> adj[N];

int fpar(int x) {
    return (x == par[x] ? x : par[x] = fpar(par[x]));
}

bool merge(int u, int v) {
    int pu = fpar(u), pv = fpar(v);
    if (pu == pv) return false;
    par[pv] = pu;
    return true;
}

void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < L; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    tin[u] = ++tim;
    for (auto& [v, i] : adj[u]) {
        if (!in_mst[i]) continue;
        if (v == p) continue;
        dist[v] = dist[u] + wv[i];
        dfs(v, u);
    }
    tout[u] = ++tim;
}

bool is_anc(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v) {
    if (is_anc(u, v)) {
        return u;
    }
    if (is_anc(v, u)) {
        return v;
    }
    for (int i = L - 1; i >= 0; i--) {
        if (is_anc(up[u][i], v)) continue;
        u = up[u][i];
    }
    return up[u][0];
}

long long distance(int u, int v) {
    return dist[u] + dist[v] - 2 * dist[lca(u, v)];
}

vector<long long> dijsktra(int s) {
    vector<long long> ret(n + 1, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    ret[s] = 0LL;
    pq.emplace(ret[s], s);
    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        if (ret[u] != w) continue;
        for (auto& [v, i] : adj[u]) {
            if (ret[v] > ret[u] + wv[i]) {
                ret[v] = ret[u] + wv[i];
                pq.emplace(ret[v], v);
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    vector<tuple<int, int, int>> edges(m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v >> wv[i];
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
        edges[i - 1] = make_tuple(i, u, v);
    }
    sort(edges.begin(), edges.end(), [&](auto& x, auto& y) {
        int i = get<0>(x), j = get<0>(y);
        return wv[i] < wv[j];
    });
    for (int i = 1; i <= m; i++) {
        par[i] = i;
    }
    for (auto& [i, u, v] : edges) {
        if (merge(u, v)) {
            in_mst[i] = true;
        } else {
           special_node[u] = special_node[v] = true;
        }
    }
    dfs(1, 1);
    vector<int> nodes;
    for (int i = 1; i <= n; i++) {
        if (special_node[i]) {
            nodes.emplace_back(i);
        }
    }
    vector<vector<long long>> sp_dist;
    for (int u : nodes) {
        sp_dist.emplace_back(dijsktra(u));
    }
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        long long ans = distance(u, v);
        for (auto& sp : sp_dist) {
            ans = min(ans, sp[u] + sp[v]);
        }
        cout << ans << '\n';
    }

    return 0;
}