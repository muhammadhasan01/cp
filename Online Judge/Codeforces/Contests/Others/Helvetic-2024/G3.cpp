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

const int N = 5e4 + 2;
const int N2 = 5e3 + 2;
const int N3 = 5e2 + 2;
const int N4 = 5e1 + 2;
const int K = 2;

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
    vector<int> values;
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            int cu = scc.comp[u];
            int cv = scc.comp[v];
            if (cu != cv) {
                int cur = min(sz[cu], sz[cv]);
                values.emplace_back(cur);
                values.emplace_back(cnt[col[u]] - cur);
            }
        }
    }
    if (color == 1 && values.empty()) {
        cout << -1 << '\n';
        return;
    }
    vector<int> occ(n + 1);
    for (int cc = 1; cc <= color; cc++) {
        values.emplace_back(0);
        values.emplace_back(cnt[cc]);
        occ[cnt[cc]]++;
    }
    sort(values.begin(), values.end());
    values.resize(unique(values.begin(), values.end()) - values.begin());
    vector<int> valColors;
    int lg = __lg(n) + 1;
    for (int x = 1; x <= n; x++) {
        for (int j = 0; j <= lg && occ[x] > 0; j++) {
            int cur = (1 << j);
            if (occ[x] >= cur) {
                valColors.emplace_back(x * cur);
                occ[x] -= cur;
            } else {
                valColors.emplace_back(x * occ[x]);
                occ[x] = 0;
            }
        }
    }

    long long ans = LLONG_MAX;

    auto calculate = [&](auto&& dp) {
        dp[0][0] = 1;
        for (int num : valColors) {
            dp[0] |= (dp[0] << num);
        }
        for (int val : values) {
            dp[1] |= (dp[0] << val);
        }
        for (int i = 1; i <= n / 2; i++) {
            if (dp[1][i]) {
                long long x = i;
                long long y = n - i;
                long long res = x * x + y * y;
                ans = min(ans, res);
            }
        }
    };

    if (N2 + N2 < n && n <= N + N) {
        array<bitset<N>, K> dp;
        calculate(dp);
    } else if (N3 + N3 < n && n <= N2 + N2) {
        array<bitset<N2>, K> dp;
        calculate(dp);
    } else if (N4 + N4 < n && n <= N3 + N3) {
        array<bitset<N3>, K> dp;
        calculate(dp);
    } else {
        array<bitset<N4>, K> dp;
        calculate(dp);
    }
    long long add = 1LL * c * (color - 1);
    cout << ans + add << '\n';
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