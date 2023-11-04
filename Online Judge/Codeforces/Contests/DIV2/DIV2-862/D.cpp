#include <bits/stdc++.h>

using namespace std;

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

    vector<int> depth(n + 1);
    vector<int> dist(n + 1);
    vector<int> dp(n + 1);
    vector<vector<int>> pref = adj;
    multiset<int> ms;

    function<void(int, int)> dfsDist = [&](int u, int p) {
        depth[u] = (u == p ? 0 : 1 + depth[p]);
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfsDist(v, u);
            dist[u] = max(dist[u], 1 + dist[v]);
        }
    };

    function<void(int, int)> DP = [&](int u, int p) {
        dp[u] = max(dist[u], depth[u]);
        if (!ms.empty()) {
            int val = *ms.rbegin();
            dp[u] = max(dp[u], val + depth[u]);
        }

        int len = adj[u].size();
        pref[u][0] = 0;
        for (int i = 0; i < len; i++) {
            int v = adj[u][i];
            if (i > 0) {
                pref[u][i] = pref[u][i - 1];
            }
            if (v == p) {
                continue;
            }
            pref[u][i] = max(pref[u][i], 1 + dist[v] - depth[u]);
        }
        int curMax = 0;
        for (int i = len - 1; i >= 0; i--) {
            int v = adj[u][i];
            if (v == p) {
                continue;
            }
            int cur = curMax;
            if (i - 1 >= 0) {
                cur = max(cur, pref[u][i - 1]);
            }
            ms.emplace(cur);
            DP(v, u);
            ms.erase(ms.find(cur));
            curMax = max(curMax, 1 + dist[v] - depth[u]);
        }
    };

    dfsDist(1, 1);
    DP(1, 1);

    vector<int> ans(n + 5);
    for (int u = 1; u <= n; u++) {
        ans[dp[u] + 1]++;
    }
    ans[1] = 1;
    for (int i = 2; i <= n; i++) {
        ans[i] += ans[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        cout << min(n, ans[i]) << " \n"[i == n];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}