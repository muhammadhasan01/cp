#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int L = 18;

int up[N][L];
int depth[N], tin[N], tout[N], tim;
vector<int> adj[N];

void dfs(int u, int p) {
    depth[u] = (u == p ? 0 : 1 + depth[p]);
    up[u][0] = p;
    tin[u] = ++tim;
    for (int i = 1; i < L; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
    }
    tout[u] = ++tim;
}

bool is_anc(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int LCA(int u, int v) {
    if (is_anc(u, v)) {
        return u;
    }
    if (is_anc(v, u)) {
        return v;
    }
    for (int i = L - 1; i >= 0; i--) {
        if (is_anc(up[u][i], v)) {
            continue;
        }
        u = up[u][i];
    }
    return up[u][0];
}

int distance(int u, int v) {
    int w = LCA(u, v);
    return depth[u] + depth[v] - 2 * depth[w];
}
