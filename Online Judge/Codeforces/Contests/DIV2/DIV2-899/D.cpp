#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<int> sz(n + 1);
    vector<int> par(n + 1);
    vector<long long> ups(n + 1);
    vector<long long> dp(n + 1);
    vector<long long> vals(n + 1);

    function<void(int, int)> compute = [&](int u, int p) {
        sz[u] = 1;
        par[u] = p;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            compute(v, u);
            dp[u] += dp[v];
            sz[u] += sz[v];
        }
        if (u != p) {
            vals[u] = 1LL * sz[u] * (a[u] ^ a[p]);
            dp[u] += vals[u];
        }
    };

    vector<long long> ans(n + 1);
    long long upVal = 0;

    function<void(int, int)> reroot = [&](int u, int p) {
        ups[u] += 1LL * (n - sz[u]) * (a[p] ^ a[u]);
        ups[u] += dp[p] - vals[p] - dp[u];
        upVal += ups[u];
        ans[u] += dp[u] - vals[u];
        ans[u] += upVal;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            reroot(v, u);
        }
        upVal -= ups[u];
    };

    compute(1, 1);
    ans[1] = dp[1];
    for (int u : adj[1]) {
        reroot(u, 1);
    }
    for (int u = 1; u <= n; u++) {
        cout << ans[u] << " \n"[u == n];
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