#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<bool> self(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (u == v) {
            self[u] = true;
            continue;
        }
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int ans = 0;
    for (int s = 0; s < n; s++) {
        if (self[s]) {
            ans = max(ans, 1);
        }
        vector<int> dist(n, -1);
        queue<int> q;
        q.emplace(s);
        dist[s] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] != -1) {
                    continue;
                }
                dist[v] = 1 + dist[u];
                q.emplace(v);
            }
        }
        ans = max(ans, *max_element(dist.begin(), dist.end()));
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}