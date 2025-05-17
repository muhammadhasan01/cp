#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> val(n + 1);
    int root = -1;
    for (int u = 1; u <= n; u++) {
        int p;
        cin >> p >> val[u];
        if (p == -1) {
            root = u;
        } else {
            adj[p].emplace_back(u);
        }
    }
    for (int u = 1; u <= n; u++) {
        if (adj[u].empty()) {
            continue;
        }
        int v = adj[u][0];
        int w = adj[u][1];
        if (val[v] > val[w]) {
            swap(adj[u][0], adj[u][1]);
        }
    }

    vector<int> bounds;
    vector<int> leaves;
    vector<int> depth(n + 1);
    vector<int> mx(n + 1);
    vector<int> mn(n + 1);

    function<void(int, int, int)> dfs = [&](int u, int l, int r) {
        if (adj[u].empty()) {
            leaves.emplace_back(u);
            bounds.emplace_back(r);
            mx[u] = val[u];
            mn[u] = val[u];
            return;
        }
        int v = adj[u][0];
        int w = adj[u][1];
        depth[v] = depth[u] + 1;
        depth[w] = depth[u] + 1;
        dfs(v, l, val[u] - 1);
        dfs(w, val[u] + 1, r);
        mn[u] = mn[v];
        mx[u] = mx[w];
    };

    vector<long double> dp(n + 1);

    function<void(int)> DP = [&](int u) {
        if (adj[u].empty()) {
            return;
        }
        int v = adj[u][0];
        int w = adj[u][1];
        dp[v] = dp[u] + mn[w];
        dp[w] = dp[u] + mx[v];
        DP(v);
        DP(w);
    };

    dfs(root, -INF, INF);
    DP(root);

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int pos = lower_bound(bounds.begin(), bounds.end(), x) - bounds.begin();
        int u = leaves[pos];
        cout << fixed << setprecision(9) << dp[u] / depth[u] << '\n';
    }
    
    return 0;
}