#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> adj(n + m + 1);
    vector<int> col(n + m + 1, -1);
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int r = min(x1, x2);
        int c = n + min(y1, y2);
        int dif = (x1 + y1 != x2 + y2);
        adj[r].emplace_back(c, dif);
        adj[c].emplace_back(r, dif);
    }

    function<bool(int)> dfs = [&](int u) {
        for (auto [v, dif] : adj[u]) {
            if (col[v] == -1) {
                col[v] = (col[u] ^ dif);
                if (!dfs(v)) {
                    return false;
                }
            } else if (col[v] != (col[u] ^ dif)) {
                return false;
            }
        }
        return true;
    };

    for (int u = 1; u <= n + m; u++) {
        if (col[u] == -1) {
            col[u] = 0;
            if (!dfs(u)) {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    cout << "YES" << '\n';
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