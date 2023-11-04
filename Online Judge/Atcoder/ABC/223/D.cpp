#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        deg[v]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int u = 1; u <= n; u++) {
        if (deg[u] == 0) {
            pq.emplace(u);
        }
    }
    vector<int> ans;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        ans.emplace_back(u);
        for (int v : adj[u]) {
            if (--deg[v] == 0) {
                pq.emplace(v);
            }
        }
    }
    if ((int) ans.size() != n) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    
    return 0;
}