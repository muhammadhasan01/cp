#include <bits/stdc++.h>

using namespace std;

// source : https://gist.github.com/dhsrhkdgus/aac67f8a374b42f37e4c184b2429bd83

const int N = 1e5 + 5;
const int L = log2(N);
const int INF = 1e9;
int n, m;
set<int> g[N];
int par[N][L + 3];
int depth[N], sz[N];
int cpar[N]; // cpar[v] : parent of v in centroid
int ans[N];

void dfsDepth(int u, int p) {
    for (auto v : g[u]) {
        if (v == p) continue;
        par[v][0] = u;
        depth[v] = depth[u] + 1;
        dfsDepth(v, u);
    }
}

void preprocess() {
    depth[1] = 0;
    par[1][0] = 1;
    dfsDepth(1, 1);
    for (int i = 1; i < L; i++) {
        for (int u = 1; u <= n; u++) {
            par[u][i] = par[par[u][i - 1]][i - 1];
        }
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    int d = depth[v] - depth[u];

    // make u & v same level
    for (int i = 0; i < L; i++) {
        if (d & (1 << i)) {
            v = par[v][i];
        }
    }

    if (u == v) return v;

    for (int i = L - 1; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

/* Centroid Decomposition */
// Calculate size of subtree by dfs
void dfsSubtree(int u, int p) {
    sz[u] = 1;
    for (auto v : g[u]) {
        if (v == p) continue;
        dfsSubtree(v, u);
        sz[u] += sz[v];
    }
}

// find Centroid
int dfsCentroid(int u, int p, int s) {
    for (auto v : g[u]) {
        if (v == p) continue;
        if (sz[v] <= s / 2) continue;
        return dfsCentroid(v, u, s);
    }
    return u;
}

// Centroid Decomposition
void decompose(int u, int p) {
    dfsSubtree(u, -1);
    int ctr = dfsCentroid(u, u, sz[u]);
    if (p == -1) p = ctr; // root of centroid tree
    cpar[ctr] = p;
    for (auto v : g[ctr]) {
        g[v].erase(ctr);
        decompose(v, ctr);
    }
    g[ctr].clear();
}

/* Handle the queries */
// color node u red
void update(int u) {
    int rNode = u;
    while (1) {
        ans[u] = min(ans[u], dist(rNode, u));
        if (u == cpar[u]) break;
        u = cpar[u];
    }
}

int query(int u) {
    int start = u;
    int minD = INF;
    while (1) {
        minD = min(minD, dist(start, u) + ans[u]);
        if (u == cpar[u]) break;
        u = cpar[u];
    }
    return minD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }

    preprocess();
    decompose(1, -1);
    fill(ans + 1, ans + 1 + n, INF);
    update(1);
    for (int i = 1; i <= m; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            update(x);
        } else if (t == 2) {
            cout << query(x) << '\n';
        }
    }


    return 0;
}
