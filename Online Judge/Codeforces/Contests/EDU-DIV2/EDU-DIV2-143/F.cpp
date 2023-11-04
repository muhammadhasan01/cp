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
    int k;
    cin >> k;
    vector<int> chips(k);
    for (int i = 0; i < k; i++) {
        cin >> chips[i];
    }
    vector<bool> vis(n + 1);
    vector<int> down(n + 1);
    vector<int> stock(n + 1);

    function<bool(int, int)> dfs = [&](int u, int p) {
        down[u] = 0;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            if (!dfs(v, u)) {
                return false;
            }
            if (!vis[v]) {
                down[u] = max(down[u], down[v] + 1);
            }
        }
        if (stock[u] == 0 || down[u] >= stock[u]) {
            return true;
        }
        if (u == p || vis[p]) {
            return false;
        }
        vis[p] = true;
        stock[p] = stock[u] - 1;
        return true;
    };

    auto can = [&](int x) -> bool {
        fill(vis.begin(), vis.end(), false);
        fill(stock.begin(), stock.end(), 0);
        fill(down.begin(), down.end(), 0);
        for (int i = 0; i < k; i++) {
            int u = chips[i];
            vis[u] = true;
            stock[u] = x / k + (i < x % k);
        }
        return dfs(1, 1);
    };

    int l = 0, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
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
        solve();
    }
    
    return 0;
}