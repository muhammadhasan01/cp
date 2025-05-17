#include <bits/stdc++.h>

using namespace std;

struct SCC {
    int n;
    vector<vector<int>> adj;
    vector<int> comp;
    int numComponent = 0;
    
    SCC(int t_n) : n(t_n), adj(t_n), comp(t_n, -1) {}
    SCC(const vector<vector<int>>& t_adj) : adj(t_adj) {
        n = t_adj.size();
        comp.assign(n, -1);
    }
 
    void addEdge(int u, int v) {
        adj[u].emplace_back(v);
    }
 
    void build(bool isDirected) {
        vector<int> tin(n), low(n);
        vector<bool> onStack(n);
        stack<int> st;
        int timer = 0;
        function<void(int, int)> tarjan = [&](int u, int p) {
            tin[u] = low[u] = ++timer;
            st.emplace(u);
            onStack[u] = true;
            for (int v : adj[u]) {
                if (!isDirected && v == p) {
                    continue;
                }
                if (tin[v] == 0) {
                    tarjan(v, u);
                    low[u] = min(low[u], low[v]);
                } else if (onStack[v]) {
                    low[u] = min(low[u], tin[v]);
                }
            }
            if (tin[u] != low[u]) {
                return;
            }
            int w = 0;
            do {
                w = st.top();
                st.pop();
                onStack[w] = 0;
                comp[w] = numComponent;
            } while (w != u && !st.empty());
            numComponent++;
        };
        for (int u = 0; u < n; u++) {
            if (tin[u] == 0) {
                tarjan(u, u);
            }
        }
    }
};

void solve() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int color = 0;
    vector<int> col(n + 1);
    
    function<void(int)> dfs = [&](int u) {
        for (int v : adj[u]) {
            if (col[v] > 0) {
                continue;
            }
            col[v] = col[u];
            dfs(v);
        }
    };

    for (int u = 1; u <= n; u++) {
        if (col[u] == 0) {
            col[u] = ++color;
            dfs(u);
        }
    }
    SCC scc(adj);
    scc.build(false);
    vector<int> colComp(scc.numComponent + 1);
    vector<vector<int>> g(scc.numComponent + 1);
    vector<int> cntComp(scc.numComponent + 1);
    for (int u = 1; u <= n; u++) {
        colComp[scc.comp[u]] = col[u];
        cntComp[scc.comp[u]]++;
        for (int v : adj[u]) {
            int cu = scc.comp[u];
            int cv = scc.comp[v];
            if (cu != cv) {
                g[cu].emplace_back(cv);
            }
        }
    }
    vector<int> sz(scc.numComponent + 1);
    vector<bool> vis(scc.numComponent + 1);

    function<void(int)> dfs2 = [&](int u) {
        vis[u] = true;
        sz[u] = cntComp[u];
        for (int v : g[u]) {
            if (vis[v]) {
                continue;
            }
            dfs2(v);
            sz[u] += sz[v];
        }
    };

    for (int u = 1; u <= scc.numComponent; u++) {
        if (!vis[u]) {
            dfs2(u);
        }
    }
    vector<int> cnt(color + 1);
    for (int u = 1; u <= n; u++) {
        cnt[col[u]]++;
    }
    vector<vector<int>> division(color + 1);
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            int cu = scc.comp[u];
            int cv = scc.comp[v];
            if (cu != cv) {
                int cur = min(sz[cu], sz[cv]);
                division[col[u]].emplace_back(cur);
                division[col[u]].emplace_back(cnt[col[u]] - cur);
            }
        }
    }
    if (color == 1 && division[1].empty()) {
        cout << -1 << '\n';
        return;
    }
    for (int cc = 1; cc <= color; cc++) {
        division[cc].emplace_back(0);
        division[cc].emplace_back(n);
        sort(division[cc].begin(), division[cc].end());
        division[cc].resize(unique(division[cc].begin(), division[cc].end()) - division[cc].begin());
    }
    vector<bool> dp(n + 1);
    dp[0] = true;
    long long ans = LLONG_MAX;
    long long add = 1LL * c * (color - 1);
    for (int cc = 1; cc <= color; cc++) {
        int num = cnt[cc];
        for (int val : division[cc]) {
            for (int j = val; j <= n; j++) {
                if (dp[j - val]) {
                    long long X = j;
                    long long Y = n - X;
                    long long cur = X * X + Y * Y + add;
                    ans = min(ans, cur);
                }
            }
        }
        vector<bool> ndp(n + 1);
        for (int j = 0; j <= n; j++) {
            ndp[j] = dp[j];
            if (j - num >= 0 && dp[j - num]) {
                ndp[j] = true;
            }
        }
        dp.swap(ndp);
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