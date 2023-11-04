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

    long long sum = 0;
    vector<int> sz(n + 1);
    vector<long long> ans(n + 1);

    function<void(int, int, int)> dfs = [&](int u, int p, int d) {
        sz[u] = 1;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u, d + 1);
            sz[u] += sz[v];
        }  
        sum += d;
    };

    function<void(int, int)> rec = [&](int u, int p) {
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            ans[v] = ans[u] - sz[v] + (n - sz[v]);
            rec(v, u);
        }
    };

    dfs(1, 1, 0);
    ans[1] = sum;
    rec(1, 1);
    for (int u = 1; u <= n; u++) {
        cout << ans[u] << '\n';
    }

    return 0;
}