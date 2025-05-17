#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].emplace_back(i);
    }
    vector<int> sz(n + 1);

    function<void(int)> dfs = [&](int u) {
        sz[u] = 1;
        for (int v : adj[u]) {
            dfs(v);
            sz[u] += sz[v];
        }
    };

    dfs(1);
    for (int u = 1; u <= n; u++) {
        cout << sz[u] - 1 << " \n"[u == n];
    }
    
    return 0;
}