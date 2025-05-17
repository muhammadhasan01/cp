#include <bits/stdc++.h>

using namespace std;

const int B = 2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int u = 2; u <= n; u++) {
        int p;
        cin >> p;
        adj[p].emplace_back(u);
    }
    vector<long long> w(n + 1);
    for (int u = 1; u <= n; u++) {
        cin >> w[u];
    }
    vector<int> d(n + 1);
    for (int u = 1; u <= n; u++) {
        cin >> d[u];
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(B));

    function<void(int)> dfs = [&](int u) {
        if (adj[u].empty()) {
            dp[u][0] = -w[u];
            dp[u][1] = w[u];
            return;
        }
        for (int v : adj[u]) {
            dfs(v);
        }
        for (int i = 0; i < 2; i++) {
            int len = (int) adj[u].size();
            vector<pair<long long, int>> values(len);
            for (int j = 0; j < len; j++) {
                int v = adj[u][j];
                values[j] = {dp[v][1 - i] - dp[v][i], v};
            }
            sort(values.rbegin(), values.rend());
            dp[u][i] = (i == 0 ? -w[u] : w[u]);
            for (int j = 0; j < len; j++) {
                int v = values[j].second;
                if (j < d[u]) {
                    dp[u][i] += dp[v][1 - i];
                } else {
                    dp[u][i] += dp[v][i];
                }
            }
        }
    };

    dfs(1);
    
    cout << max(abs(dp[1][0]), abs(dp[1][1])) << '\n';
    
    return 0;
}