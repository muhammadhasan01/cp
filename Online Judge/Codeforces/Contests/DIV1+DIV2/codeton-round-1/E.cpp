#include <bits/stdc++.h>

using namespace std;

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

    vector<int> a(n + 1);

    function<void(int, int, int)> dfs = [&](int u, int p, int x) {
        a[u] = x;
        for (auto v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u, x == 0 ? 1 : -x);
            a[u] -= x == 0 ? 1 : -x;
        }
    };

    dfs(1, 1, 0);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }
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