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

    int getBeforeLca(int u, int v) {
        for (int i = l - 1; i >= 0; i--) {
            if (!isAncestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return u;
    }

    int distance(int u, int v) {
        int w = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[w];
    }
};

template<typename T>
vector<pair<T, int>> getFreq(vector<T>& v) {
    vector<pair<T, int>> freq;
    for (T x : v) {
        if (freq.empty() || freq.back().first != x) {
            freq.emplace_back(x, 1);
            continue;
        }
        auto [_, cnt] = freq.back();
        freq.pop_back();
        freq.emplace_back(x, cnt + 1);
    }
    return freq;
}

void solve() {
    int n;
    cin >> n;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<vector<int>> colors(n + 1);
    vector<vector<int>> st(n + 1);

    LCA lca(n + 1, 1, adj);

    function<void(int, int)> dfs = [&](int u, int p) {
        if (u != p) {
            if (st[c[u]].empty()) {
                colors[0].emplace_back(c[u]);
            } else {
                int node = st[c[u]].back();
                int v = lca.getBeforeLca(u, node);
                colors[v].emplace_back(c[u]);
            }
        }
        st[c[u]].emplace_back(u);
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
        }
        st[c[u]].pop_back();
    };

    dfs(1, 1);
    long long ans = 0;
    for (int u = 0; u <= n; u++) {
        sort(colors[u].begin(), colors[u].end());
        for (auto [_, cnt] : getFreq(colors[u])) {
            ans += 1LL * cnt * (cnt - 1) / 2;
            if (u > 0) {
                ans += cnt;
            }
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}