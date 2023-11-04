#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> e(n);
    for (int i = 0; i < n; i++) {
        cin >> e[i];
    }
    vector<int> deg(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[v].emplace_back(u);
        deg[u]++;
    }
    deque<int> dq;
    vector<int> dp(n);
    for (int u = 0; u < n; u++) {
        if (deg[u] == 0) {
            if (e[u] == 0) {
                dq.emplace_front(u);
            } else {
                dq.emplace_back(u);
                dp[u] = 1;
            }
        }
    }
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        for (int v : adj[u]) {
            dp[v] = max(dp[v], dp[u] + (e[v] == 1 && e[u] == 0));
            if (--deg[v] == 0) {
                if (e[v] == 0) {
                    dq.emplace_front(v);
                } else {
                    dq.emplace_back(v);
                }
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
    
    return 0;
}