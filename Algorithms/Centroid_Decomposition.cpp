const int N = 1e5 + 10;

int nodes;
vector<int> adj[N];
deque<int> dist[N];
int parc[N], sz[N];
bool checked[N];

void dfs(int u, int p) {
    nodes++; sz[u] = 1;
    for (auto v : adj[u]) {
        if (v == p || checked[v]) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void dfs2(int u, int p, int d) {
    dist[u].emplace_front(d);
    for (auto v : adj[u]) {
        if (v == p || checked[v]) continue;
        dfs2(v, u, d + 1);
    }
}

int centroid(int u, int p) {
    for (auto v : adj[u]) {
        if (v == p || checked[v]) continue;
        if (sz[v] > nodes) return centroid(v, u);
    }
    return u;
}

void decompose(int u, int p) {
    nodes = 0; dfs(u, u); nodes /= 2;
    int v = centroid(u, u);
    checked[v] = 1;
    dfs2(v, v, 0);
    parc[v] = p;
    for (auto w : adj[v]) {
        if (checked[w]) continue;
        decompose(w, v);
    }
}
