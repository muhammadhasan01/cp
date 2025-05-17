#include <bits/stdc++.h>

using namespace std;

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

const int B = 550;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int> a(n + 1);
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<vector<int>> nodes(n + 1);
    for (int u = 1; u <= n; u++) {
        int c = a[u];
        if (cnt[c] < B) {
            nodes[c].emplace_back(u);
        }
    }
    LCA lca(n + 1, 1, adj);
    vector<int> big;
    long long ans = 0;
    for (int c = 1; c <= n; c++) {
        if (cnt[c] == 0) {
            continue;
        }
        if (cnt[c] >= B) {
            big.emplace_back(c);
            continue;
        }
        int len = (int) nodes[c].size();
        for (int i = 0; i + 1 < len; i++) {
            for (int j = i + 1; j < len; j++) {
                ans += lca.distance(nodes[c][i], nodes[c][j]);
            }
        }
    }

    auto solve = [&](int color) -> long long {
        vector<long long> dp(n + 1);
        vector<long long> sz(n + 1);
        long long ret = 0;

        function<void(int, int)> dfs = [&](int u, int p) {
            sz[u] = (a[u] == color);
            for (int v : adj[u]) {
                if (v == p) {
                    continue;
                }
                dfs(v, u);
                sz[u] += sz[v];
                dp[u] += (dp[v] + sz[v]);
            }
        };

        function<void(int, int)> reroot = [&](int u, int p) {
            if (u != p) {
                sz[u] += sz[p];
                dp[u] += (dp[p] + sz[p]);
            }
            if (a[u] == color) {
                ret += dp[u];
            }
            for (int v : adj[u]) {
                if (v == p) {
                    continue;
                }
                long long dpu = dp[u];
                long long szu = sz[u];
                dp[u] -= (dp[v] + sz[v]);
                sz[u] -= sz[v];
                reroot(v, u);
                dp[u] = dpu;
                sz[u] = szu;
            }
        };

        dfs(1, 1);
        reroot(1, 1);

        return ret / 2;
    };

    for (int color : big) {
        ans += solve(color);
    }
    cout << ans << '\n';
    
    return 0;
}