#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        deg[u]++;
        deg[v]++;
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int x, int y) {
        return deg[x] < deg[y];
    });
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        int u = ord[i];
        for (int v : adj[u]) {
            if (deg[v] > deg[u]) {
                dp[v] = max(dp[v], 1 + dp[u]);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) + 1 << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}