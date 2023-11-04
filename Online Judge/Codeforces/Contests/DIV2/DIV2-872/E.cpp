#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
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

    int ans = 0;
    vector<map<int, int>> st(n + 1);

    function<void(int, int)> dfs = [&](int u, int p) {
        int mx = 1, child = 0;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            a[v] ^= a[u];
            dfs(v, u);
            child++;
            if (st[u].size() < st[v].size()) {
                swap(st[u], st[v]);
            }
            for (auto [val, cnt] : st[v]) {
                st[u][val] += cnt;
                mx = max(mx, st[u][val]);
            }
        }
        if (child == 0) {
            st[u][a[u]] = 1;
            return;
        }
        ans += child - mx;
        if (mx > 1) {
            for (auto it = st[u].begin(); it != st[u].end(); ) {
                if (it->second != mx) {
                    it = st[u].erase(it);
                } else {
                    it->second = 1;
                    it = next(it);
                }
            }
        }
    };

    dfs(1, 1);
    cout << ans + !(st[1].count(0)) << '\n';

    return 0;
}