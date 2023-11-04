#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }
    int root = -1;
    for (int u = 1; u <= n; u++) {
        int len = (int) adj[u].size();
        if (len > 2) {
            cout << -1 << '\n';
            return;
        }
        if (len == 1) {
            root = u;
        }
    }
    vector<bool> vis(n + 1);
    queue<pair<int, int>> q;
    q.emplace(root, 2);
    vis[root] = true;
    vector<int> ans(n + 1);
    while (!q.empty()) {
        auto [u, val] = q.front();
        q.pop();
        for (auto [v, idx] : adj[u]) {
            if (vis[v]) {
                continue;
            }
            ans[idx] = val;
            int newVal = val == 2 ? 3 : 2;
            q.emplace(v, newVal);
            vis[v] = true;
        }
    }
    for (int i = 2; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
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