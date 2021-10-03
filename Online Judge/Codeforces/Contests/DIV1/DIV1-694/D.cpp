#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int> res(n, -1);
    res[0] = 1;
    queue<int> q;
    for (int x : adj[0]) {
        q.emplace(x);
        res[x] = 0;
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (res[v] == -1) {
                res[v] = 1;
                for (int x : adj[v]) {
                    if (res[x] == -1) {
                        res[x] = 0;
                        q.emplace(x);
                    }
                }
            }
        }
    }
    if (*min_element(res.begin(), res.end()) == -1) {
        cout << "NO" << '\n';
        return;
    }
    vector<int> ans;
    for (int u = 0; u < n; u++) {
        if (res[u] == 1) {
            ans.emplace_back(u + 1);
        }
    }
    int len = ans.size();
    cout << "YES" << '\n';
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }
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