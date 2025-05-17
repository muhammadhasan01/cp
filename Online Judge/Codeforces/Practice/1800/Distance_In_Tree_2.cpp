#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int> par(n + 1);
    vector dp(n + 1, vector<int>(k + 1));

    function<void(int, int)> DP = [&](int u, int p) {
        par[u] = p;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            DP(v, u);
            for (int j = 1; j <= k; j++) {
                dp[u][j] += dp[v][j - 1];
            }
        }
        dp[u][0] = 1;
    };

    DP(1, 1);

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i][k];
        int u = i;
        int v = par[u];
        int j = k - 1;
        while (u != v && j >= 0) {
            ans += dp[v][j];
            if (j - 1 >= 0) {
                ans -= dp[u][j - 1];
            }
            u = v;
            v = par[v];
            j--;
        }
    }
    cout << ans / 2 << '\n';

    return 0;
}