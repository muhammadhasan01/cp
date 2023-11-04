#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int> comp(n + 1, -1);

    function<void(int)> dfs = [&](int u) {
        for (int v : adj[u]) {
            if (comp[v] == -1) {
                comp[v] = comp[u];
                dfs(v);
            }
        }
    };

    int num = 0;
    for (int u = 1; u <= n; u++) {
        if (comp[u] == -1) {
            comp[u] = ++num;
            dfs(u);
        }
    }

    vector<bool> isCycle(n + 1, true);
    for (int u = 1; u <= n; u++) {
        if ((int) adj[u].size() != 2) {
            isCycle[comp[u]] = false;
        }
    }
    int ans = 0;
    for (int i = 1; i <= num; i++) {
        if (isCycle[i]) {
            ++ans;
        }
    }
    cout << ans << '\n';
    
    return 0;
}