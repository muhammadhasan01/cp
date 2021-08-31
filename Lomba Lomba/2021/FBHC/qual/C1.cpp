#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    function<int(int, int)> dfs = [&](int u, int p) {
        int ret = 0;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            ret = max(ret, dfs(v, u));
        }
        ret += c[u];
        return ret;
    };
    int ans = c[1];
    vector<int> res;
    for (int u : adj[1]) {
        res.emplace_back(dfs(u, 1));
    }
    sort(res.rbegin(), res.rend());
    int len = res.size();
    for (int i = 0; i < min(2, len); i++) {
        ans += res[i];
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}