#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

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
    int k;
    cin >> k;
    vector<pair<int, int>> E(k);
    for (int i = 0; i < k; i++) {
        cin >> E[i].first >> E[i].second;
    }
    vector<int> par(n + 1);
    vector<int> tin(n + 1);
    vector<int> tout(n + 1);
    vector<int> mask(n + 1);
    int tim = 0;

    function<void(int, int)> dfs = [&](int u, int p) {
        par[u] = p;
        tin[u] = ++tim;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
        }
        tout[u] = ++tim;
    };

    dfs(1, 1);
    
    auto isAncestor = [&](int u, int v) -> bool {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    };

    for (int i = 0; i < k; i++) {
        auto [u, v] = E[i];
        for (int rep = 0; rep < 2; rep++) {
            int x = u;
            int y = v;
            while (!isAncestor(x, y)) {
                mask[x] |= (1 << i);
                x = par[x];
            }
            swap(u, v);
        }
    }

    vector<int> masks;
    for (int u = 1; u <= n; u++) {
        masks.emplace_back(mask[u]);
    }
    sort(masks.begin(), masks.end());
    masks.resize(unique(masks.begin(), masks.end()) - masks.begin());
    vector<int> dp(1 << k, INF);
    dp[0] = 0;
    for (int m = 0; m < (1 << k); m++) {
        if (dp[m] == INF) {
            continue;
        }
        for (int msk : masks) {
            dp[m | msk] = min(dp[m | msk], 1 + dp[m]);
        }
    }
    cout << dp[(1 << k) - 1] << '\n';
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