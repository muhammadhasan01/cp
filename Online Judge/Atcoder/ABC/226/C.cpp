#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> T(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> T[i];
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            adj[i].emplace_back(x);
        }
    }
    vector<bool> vis(n + 1);

    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (vis[v]) {
                continue;
            }
            dfs(v);
        }
    };

    dfs(n);
    long long ans = 0;
    for (int u = 1; u <= n; u++) {
        if (vis[u]) {
            ans += T[u];
        }
    }
    cout << ans << '\n';
    
    return 0;
}