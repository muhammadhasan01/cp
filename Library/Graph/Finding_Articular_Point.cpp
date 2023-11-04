int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> vis;
vector<int> tin, low;
int timer;

void dfs(int u, int p = -1) {
    vis[u] = true;
    tin[u] = low[u] = timer++;
    int children = 0;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (vis[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (tin[u] <= low[v] && p != -1) {
                IS_CUTPOINT(u);
            }
            ++children;
        }
    }
    if (p == -1 && children > 1) {
        IS_CUTPOINT(u);
    }
}

void find_cutpoints() {
    timer = 0;
    vis.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}
