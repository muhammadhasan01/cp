struct LCA {
    int n, l;
    int tim;
    vector<int> depth, tin, tout;
    vector<vector<int>> up;

    LCA(int n, int root, const vector<vector<int>>& adj) : n(n), depth(n), tin(n), tout(n) {
        l = ceil(log2(n)) + 2;
        up.assign(n, vector<int>(l));
        function<void(int, int)> process = [&](int u, int p) {
            depth[u] = (u == p ? 0 : 1 + depth[p]);
            up[u][0] = p;
            tin[u] = ++tim;
            for (int v : adj[u]) {
                if (v == p) {
                    continue;
                }
                process(v, u);
            }
            tout[u] = ++tim;
        };
        process(root, root);
        for (int i = 1; i < l; i++) {
            for (int u = 0; u < n; u++) {
                up[u][i] = up[up[u][i - 1]][i - 1];
            }
        }
    }

    bool isAncestor(int u, int v) {
        return (tin[u] <= tin[v] && tout[u] >= tout[v]);
    }
    
    int lca(int u, int v) {
        if (isAncestor(u, v)) {
            return u;
        }
        if (isAncestor(v, u)) {
            return v;
        }
        for (int i = l - 1; i >= 0; i--) {
            if (!isAncestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return up[u][0];
    }

    int distance(int u, int v) {
        int w = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[w];
    }
};