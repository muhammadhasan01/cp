#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        deg[v]++;
    }
    vector<int> dp(n + 1);
    queue<int> q;
    for (int u = 1; u <= n; u++) {
        if (deg[u] == 0) {
            q.emplace(u);
        }
    }
    dp[1] = 1;
    vector<int> par(n + 1, -1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dp[u] > 0 && dp[v] < dp[u] + 1) {
                dp[v] = dp[u] + 1;
                par[v] = u;
            }
            if (--deg[v] == 0) {
                q.emplace(v);
            }
        }
    }
    if (dp[n] == 0) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    vector<int> ans;
    int u = n;
    while (u != 1) {
        ans.emplace_back(u);
        u = par[u];
    }
    ans.emplace_back(1);
    reverse(ans.begin(), ans.end());
    int len = dp[n];
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }
    
    return 0;
}