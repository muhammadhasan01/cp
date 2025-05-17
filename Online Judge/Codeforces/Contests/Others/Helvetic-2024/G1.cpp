#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int> sz(n + 1);

    function<void(int, int)> dfs = [&](int u, int p) {\
        sz[u] = 1;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            sz[u] += sz[v];
        }
    };

    dfs(1, 1);
    long long ans = LLONG_MAX;
    for (int u = 2; u <= n; u++) {
        long long x = sz[u];
        long long y = n - sz[u];
        ans = min(ans, x * x + y * y);
    }
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