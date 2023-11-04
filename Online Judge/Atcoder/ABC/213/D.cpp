#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    for (int u = 1; u <= n; u++) {
        sort(adj[u].begin(), adj[u].end());
    }

    vector<int> ans;
    
    function<void(int, int)> dfs = [&](int u, int p) {
        ans.emplace_back(u);
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            ans.emplace_back(u);
        }
    };

    dfs(1, 1);

    int len = ans.size();
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }
    
    return 0;
}