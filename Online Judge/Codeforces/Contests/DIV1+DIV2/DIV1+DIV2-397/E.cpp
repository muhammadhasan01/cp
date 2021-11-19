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
    int root = -1;
    function<int(int, int)> dfs = [&](int u, int p) {
        set<int> h;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            int res = dfs(v, u);
            if (res == -1) {
                return -1;
            }
            h.emplace(res + 1);
        }
        int len = h.size();
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return *h.begin();
        }
        if (p == 0 && len == 2) {
            return *h.begin() + *h.rbegin();
        }
        root = u;
        return -1;
    };
    int ans = dfs(1, 0);
    if (ans == -1 && root != -1) {
        ans = dfs(root, 0);
    }
    if (ans == -1) {
        cout << ans << '\n';
        return 0;
    }
    while (ans % 2 == 0) {
        ans /= 2;
    }
    cout << ans << '\n';
    
    return 0;
}