#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    long long ans = 0;
    vector<long long> dp(n);
    vector<vector<int>> childs(n);

    function<void(int, int)> dfs = [&](int u, int p) {
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            childs[u].emplace_back(v);
        }
        sort(childs[u].begin(), childs[u].end(), [&](int& i, int& j) {
            return dp[i] > dp[j];
        });
        int numChild = 0;
        dp[u] = a[u];
        ans = max(ans, a[u]);
        long long cur = a[u];
        for (int v : childs[u]) {
            ++numChild;
            cur += dp[v];
            if (numChild > 1) {
                dp[u] = max(dp[u], cur);
            }
            if (numChild == 2) {
                ans = max(ans, cur - a[u]);
            } else {
                ans = max(ans, cur);
            }
        }
        for (int v : childs[u]) {
            dp[u] = max(dp[u], dp[v]);
        }
    };

    dfs(0, 0);

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