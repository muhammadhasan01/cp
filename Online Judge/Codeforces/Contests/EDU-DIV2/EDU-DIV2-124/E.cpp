#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> adj(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    long long ans = 0;
    // Count for every cycle
    vector<bool> vis(2 * n + 1);
    for (int s = 1; s <= n; s++) {
        if (vis[s]) {
            continue;
        }

        vector<int> nodes;
        function<void(int)> dfs = [&](int u) {
            vis[u] = true;
            nodes.emplace_back(u);
            for (int v : adj[u]) {
                if (vis[v]) {
                    continue;
                }
                dfs(v);
            }
        };
        dfs(s);

        int m = (int) nodes.size();
        assert(m % 2 == 0);
        // Count the cycle as a whole
        {
            int minL = n, maxL = -1;
            int minR = n, maxR = -1;
            for (int u : nodes) {
                if (u <= n) {
                    minL = min(minL, u);
                    maxL = max(maxL, u);
                } else if (u > n) {
                    minR = min(minR, u - n);
                    maxR = max(maxR, u - n);
                }
            }
            ans += 1LL * (m / 2) * minL * (n - maxL + 1) * minR * (n - maxR + 1);
        }
        // Count on fixing a[i] with a[i + 1]
        for (int i = 0; i < m; i++) {
            int minL = n, maxL = -1;
            int minR = n, maxR = -1;
            for (int j = 0; j < m; j++) {
                int u = nodes[(i + j) % m];
                if (u <= n) {
                    minL = min(minL, u);
                    maxL = max(maxL, u);
                } else if (u > n) {
                    minR = min(minR, u - n);
                    maxR = max(maxR, u - n);
                }
                if (j % 2 == 0) {
                    continue;
                }
                int l1 = minL, r1 = maxL;
                int l2 = minR, r2 = maxR;
                int ex = nodes[(i + m - 1) % m];
                if (i % 2 == 1) {
                    swap(l1, l2);
                    swap(r1, r2);
                } else {
                    ex -= n;
                }
                if (ex < l2) {
                    ans += 1LL * l1 * (n - r1 + 1) * (l2 - ex) * (n - r2 + 1);
                }
                if (ex > r2) {
                    ans += 1LL * l1 * (n - r1 + 1) * l2 * (ex - r2);
                }
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}