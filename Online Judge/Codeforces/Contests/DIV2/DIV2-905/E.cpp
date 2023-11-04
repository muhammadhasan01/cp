#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, T;
    cin >> n >> T;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i <= T; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int u, v;
            cin >> u >> v;
            adj[u].emplace_back(v, i);
            adj[v].emplace_back(u, i);
        }
    }
    int k;
    cin >> k;
    vector<int> a(k + 1);
    vector<set<int>> pos(T + 1);
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        pos[a[i]].emplace(i);
    }
    for (int tt = 1; tt <= T; tt++) {
        pos[tt].emplace(INF + 5);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dp(n + 1, INF);
    dp[1] = 0;
    pq.emplace(dp[1], 1);
    while (!pq.empty()) {
        auto [idx, u] = pq.top();
        pq.pop();
        if (dp[u] != idx) {
            continue;
        }
        for (auto& [v, t] : adj[u]) {
            int nidx = *pos[t].upper_bound(idx);
            if (nidx < dp[v]) {
                dp[v] = nidx;
                pq.emplace(dp[v], v);
            }
        }
    }
    if (dp[n] == INF) {
        dp[n] = -1;
    }
    cout << dp[n] << '\n';
    
    return 0;
}