#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int K = 2;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    if (n == 2) {
        cout << 2 << ' ' << 2 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        return;
    }
    vector<vector<pii>> dp(n + 1, vector<pii>(K));

    auto add = [&](pii& lhs, pii& rhs) -> void {
        lhs.first += rhs.first;
        lhs.second += rhs.second;
    };

    function<void(int, int)> dfs = [&](int u, int p) {
        dp[u][1] = {1, -(int) adj[u].size()};
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            int take = dp[v][0] > dp[v][1] ? 0 : 1;
            add(dp[u][0], dp[v][take]);
            add(dp[u][1], dp[v][0]);
        }
    };

    dfs(1, 1);
    vector<int> ans(n + 1);

    function<void(int, int, int)> backtrack = [&](int u, int p, int take) {
        ans[u] = (take ? (int) adj[u].size() : 1);
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            if (take) {
                backtrack(v, u, 0);
            } else {
                backtrack(v, u, dp[v][0] > dp[v][1] ? 0 : 1);
            }
        }
    };

    int take = dp[1][0] > dp[1][1] ? 0 : 1;
    backtrack(1, 1, take);
    auto [comp, negsum] = dp[1][take];
    cout << comp << ' ' << n - comp - negsum << '\n';
    for (int u = 1; u <= n; u++) {
        cout << ans[u] << " \n"[u == n];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}