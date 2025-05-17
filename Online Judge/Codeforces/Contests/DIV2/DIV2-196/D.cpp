#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, d;
    cin >> n >> m >> d;
    vector<bool> affected(n + 1);
    for (int i = 0; i < m; i++) {
        int u;
        cin >> u;
        affected[u] = true;
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int> dp(n + 1, -1);
    vector<vector<int>> pre(n + 1);
    vector<vector<int>> suf(n + 1);

    function<void(int, int)> dfs = [&](int u, int p) {
        if (affected[u]) {
            dp[u] = 0;
        }
        int len = (int) adj[u].size();
        pre[u].resize(len);
        for (int i = 0; i < len; i++) {
            int v = adj[u][i];
            if (v != p) {
                dfs(v, u);
                if (dp[v] != -1) {
                    dp[u] = max(dp[u], 1 + dp[v]);
                }
            }
            pre[u][i] = v != p ? dp[v] : -1;
            if (i > 0) {
                pre[u][i] = max(pre[u][i], pre[u][i - 1]);
            }
        }
        suf[u].resize(len);
        for (int i = len - 1; i >= 0; i--) {
            int v = adj[u][i];
            suf[u][i] = v == p ? -1 : dp[v];
            if (i + 1 < len) {
                suf[u][i] = max(suf[u][i], suf[u][i + 1]);
            }
        }
    };

    int ans = 0;

    function<void(int, int, int)> reroot = [&](int u, int p, int up) {
        int mx = max(dp[u], up);
        if (mx <= d) {
            ans++;
        }
        int len = (int) adj[u].size();
        for (int i = 0; i < len; i++) {
            int v = adj[u][i];
            if (v == p) {
                continue;
            }
            int cur = -1;
            if (i > 0 && pre[u][i - 1] != -1) {
                cur = max(cur, pre[u][i - 1] + 2);
            }
            if (i + 1 < len && suf[u][i + 1] != -1) {
                cur = max(cur, suf[u][i + 1] + 2);
            }
            if (up != -1) {
                cur = max(cur, 1 + up);
            }
            if (affected[u]) {
                cur = max(cur, 1);
            }
            reroot(v, u, cur);
        }
    };

    dfs(1, 1);
    reroot(1, 1, -1);

    cout << ans << '\n';
    
    return 0;
}