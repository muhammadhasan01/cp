#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> X(n + 1), Y(n + 1);
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        X[x] = i;
        Y[y] = i;
        if (x != y) {
            ++ans;
        }
    }
    vector<vector<int>> adj(m + 1);
    for (int i = 1; i <= n; i++) {
        int u = X[i];
        int v = Y[i];
        if (u == v || u == 0 || v == 0) {
            continue;
        }
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<bool> vis(m + 1);
    function<bool(int, int)> dfs = [&](int u, int p) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            if (vis[v]) {
                return true;
            }
            if (dfs(v, u)) {
                return true;
            }
        }
        return false;
    };

    for (int u = 1; u <= m; u++) {
        if (vis[u] == 0) {
            if (dfs(u, u)) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}