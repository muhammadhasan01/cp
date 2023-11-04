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
    vector<int> dp(n + 1, -1);
    vector<int> par(n + 1, - 1);

    function<void(int, int)> dfs = [&](int u, int p) {
        dp[u] = 0;
        par[u] = p;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            if (dp[v] == 0) {
                dp[u] = 1;
            }
        }
    };

    int ans = 0;
    vector<int> temp(n + 1);
    vector<int> fst(n + 1), lst(n + 1);

    function<void(int, int)> reroot = [&](int u, int p) {
        if (dp[u] == 0) {
            ++ans;
        }
        int len = (int) adj[u].size();
        fst[u] = n + 1, lst[u] = -1;
        for (int i = 0; i < len; i++) {
            int v = adj[u][i];
            if (v == p) {
                continue;
            }
            if (dp[v] == 0) {
                fst[u] = min(fst[u], i);
                lst[u] = max(lst[u], i);
            }
        }
        for (int i = 0; i < len; i++) {
            int v = adj[u][i];
            if (v == p) {
                continue;
            }
            temp[v] = dp[v];
            if (dp[v] == 0) {
                if (!(i > fst[u] || i < lst[u])) {
                    if (!(par[u] != u && dp[par[u]] == 0)) {
                        dp[v] = 1;
                    }
                }
            }
            reroot(v, u);
            dp[v] = temp[v];
        }
    };

    dfs(1, 1);
    reroot(1, 1);
    cout << ans << '\n';
    
    return 0;
}