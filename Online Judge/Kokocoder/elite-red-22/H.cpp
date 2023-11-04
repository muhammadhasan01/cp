#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    auto can = [&](int val) -> bool {
        vector<int> dp(n + 1);
        
        function<void(int, int)> dfs = [&](int u, int p) {
            int sum = 0;
            for (int v : adj[u]) {
                if (v == p) {
                    continue;
                }
                dfs(v, u);
                sum += dp[v];
            }
            dp[u] = max(sum - 1, 0) + (a[u] >= val);
        };

        dfs(1, 1);
        return dp[1] > 0;
    };

    int l = 1, r = INF, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    
    return 0;
}