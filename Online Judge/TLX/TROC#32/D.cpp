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

    vector<int> col(n + 1, -1);

    function<bool(int, int)> dfs = [&](int u, int cur) {
        col[u] = cur;
        for (int v : adj[u]) {
            if (col[v] == -1) {
                if (!dfs(v, 1 - cur)) {
                    return false;
                }
            } else if (col[v] == cur) {
                return false;
            }
        }
        return true;
    };

    for (int u = 1; u <= n; u++) {
        if (col[u] == -1) {
            if (!dfs(u, 1)) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    vector<int> ans;
    for (int u = 1; u <= n; u++) {
        if (col[u] == 0) {
            ans.emplace_back(u);
        }
    }
    int len = ans.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }

    return 0;
}