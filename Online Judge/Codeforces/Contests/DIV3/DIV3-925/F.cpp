#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    set<pair<int, int>> st;
    for (int i = 0; i < k; i++) {
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        for (int j = 2; j < n; j++) {
            int u = a[j - 1];
            int v = a[j];
            if (st.find({u, v}) == st.end()) {
                st.emplace(u, v);
                adj[u].emplace_back(v);
            }
        }
    }

    vector<int> col(n + 1, -1);

    function<bool(int)> dfs = [&](int u) {
        col[u] = 1;
        for (int v : adj[u]) {
            if (col[v] == -1) {
                if (dfs(v)) {
                    return true;
                }
            } else if (col[v] == 1) {
                return true;
            }
        }
        col[u] = 2;
        return false;
    };

    for (int u = 1; u <= n; u++) {
        if (col[u] == -1) {
            if (dfs(u)) {
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
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}