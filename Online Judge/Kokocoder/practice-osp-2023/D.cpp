#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, x, y;
    cin >> n >> x >> y;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int> sz(n + 1);
    
    function<void(int, int)> dfs = [&](int u, int p) {
        sz[u] = 1;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            sz[u] += sz[v];
        }
    };

    dfs(x, x);
    int Y = sz[y];
    dfs(y, y);
    int X = sz[x];
    cout << 1LL * n * (n - 1) - 1LL * X * Y << '\n';
    
    return 0;
}