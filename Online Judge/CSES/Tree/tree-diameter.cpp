#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    pair<int, int> furthest = {-1, -1};

    function<void(int, int, int)> dfs = [&](int u, int p, int d) {
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u, d + 1);
        }
        furthest = max(furthest, {d, u});
    };

    dfs(1, 1, 0);
    dfs(furthest.second, furthest.second, 0);
    cout << furthest.first << '\n';
    
    return 0;
}