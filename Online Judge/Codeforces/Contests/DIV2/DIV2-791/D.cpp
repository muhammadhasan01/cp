#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    long long k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        auto& [u, v] = edges[i];
        cin >> u >> v;
        --u;
        --v;
    }

    auto can = [&](int x) -> bool {
        vector<vector<int>> adj(n);
        vector<int> deg(n);
        for (auto [u, v] : edges) {
            if (a[u] > x || a[v] > x) {
                continue;
            }
            adj[u].emplace_back(v);
            deg[v]++;
        }
        queue<int> q;
        vector<int> dp(n);
        for (int u = 0; u < n; u++) {
            if (a[u] <= x && deg[u] == 0) {
                q.emplace(u);
                dp[u] = 1;
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if ((long long) dp[u] >= k) {
                return true;
            }
            for (int v : adj[u]) {
                dp[v] = max(dp[v], 1 + dp[u]);
                if (--deg[v] == 0) {
                    q.emplace(v);
                }
            }
        }
        for (int u = 0; u < n; u++) {
            if (a[u] > x) {
                continue;
            }
            if (deg[u] > 0) {
                return true;
            }
        }
        return false;
    };

    int l = 1, r = INF, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';

    return 0;
}