#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
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

    vector<int> ans(n + 1);
    vector<int> cnt(n + 1);
    
    function<void(int, int)> up = [&](int u, int p) {
        ans[u] = c[u];
        cnt[u] = c[u];
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            up(v, u);
            cnt[u] += cnt[v];
            ans[u] |= c[v];
            ans[u] |= (cnt[v] > 1 && ans[v]);
        }
    };

    function<void(int, int)> down = [&](int u, int p) {
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            ans[v] |= c[u];
            ans[v] |= ((cnt[1] - cnt[v]) > 1 && ans[u]);
            down(v, u);
        }
    };

    up(1, 1);
    down(1, 1);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
    
    return 0;
}