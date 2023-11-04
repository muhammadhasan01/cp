template<class Info>
struct LCARMQ {
    int n, l;
    int tim;
    vector<int> depth, tin, tout;
    vector<vector<int>> up;
    vector<Info> values;
    vector<vector<Info>> sp;

    LCARMQ(int n, int root, const vector<vector<int>>& adj, const vector<Info>& val) : n(n), values(val), depth(n), tin(n), tout(n) {
        assert((int) val.size() == n);
        assert((int) adj.size() == n);
        l = ceil(log2(n)) + 2;
        up.assign(n, vector<int>(l));
        sp.assign(n, vector<Info>(l));
        function<void(int, int)> process = [&](int u, int p) {
            depth[u] = (u == p ? 0 : 1 + depth[p]);
            up[u][0] = p;
            sp[u][0] = val[u] + val[p];
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
                sp[u][i] = sp[u][i - 1] + sp[up[u][i - 1]][i - 1];
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

    Info queryPath(int u, int v) {
        int w = lca(u, v);
        Info result = Info();
        for (int x : {u, v}) {
            result += val[x];
            for (int i = l - 1; i >= 0; i--) {
                if (depth[up[x][i]] >= depth[w]) {
                    result += sp[x][i];
                    x = up[x][i];
                }
            }
        }
        return result;
    }

    int distance(int u, int v) {
        int w = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[w];
    }
};

struct Info {
    long long val;
    Info() : val(-LLONG_MAX) {}
    Info(long long v) : val(v) {}
};

Info operator+(const Info& lhs, const Info& rhs) {
    return Info(max(lhs.val, rhs.val));
}