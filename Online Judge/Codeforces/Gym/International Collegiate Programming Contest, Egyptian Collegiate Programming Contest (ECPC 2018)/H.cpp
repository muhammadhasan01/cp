#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, s, l, k;
    cin >> n >> m >> s >> l >> k;
    --s;
    vector<vector<pair<int, int>>> adj(n);
    vector<int> maxi(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        maxi[u] = max(maxi[u], w);
        maxi[v] = max(maxi[v], w);
    }
    vector<int> dist(n, -1);
    {
        dist[s] = 0;
        queue<int> q;
        q.emplace(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& [v, w] : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = 1 + dist[u];
                    q.emplace(v);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int rem = l - dist[i];
        if (rem <= 0) {
            continue;
        }
        if (rem >= l - k + 1) {
            ans = max(ans, maxi[i]);
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("path.in", "r", stdin);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}