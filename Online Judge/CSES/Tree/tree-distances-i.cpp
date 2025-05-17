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
    vector<int> ans(n + 1);
    vector<int> fir(n + 1);
    vector<int> sec(n + 1);

    function<void(int, int)> dfs = [&](int u, int p) {
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            if (fir[v] + 1 > fir[u]) {
                sec[u] = fir[u];
                fir[u] = fir[v] + 1;
            } else {
                sec[u] = max(sec[u], fir[v] + 1);
            }
        }
    };

    function<void(int, int, int)> reroot = [&](int u, int p, int up) {
        ans[u] = max(fir[u], up);
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            int cur = fir[u] == fir[v] + 1 ? sec[u] : fir[u];
            reroot(v, u, max(up, cur) + 1);
        }
    };

    dfs(1, 1);
    reroot(1, 1, 0);

    for (int u = 1; u <= n; u++) {
        cout << ans[u] << " \n"[u == n];
    }
    
    return 0;
}