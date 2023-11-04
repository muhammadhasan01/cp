#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].emplace_back(v);
    }
    vector<int> depth(n);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            depth[v] = max(depth[v], depth[u] + (h[v] < h[u]));
        }
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int& i, int& j) {
        return h[i] < h[j];
    });
    long long mx = 0;
    for (int u = 0; u < n; u++) {
        mx = max(mx, 1LL * depth[u] * k + h[u]);
    }
    queue<int> q;

    auto update = [&](int u, int val) {
        if (val <= depth[u]) {
            return;
        }
        depth[u] = val;
        mx = max(mx, 1LL * depth[u] * k + h[u]);
        q.emplace(u);
    };

    long long ans = mx - h[ord[0]];
    for (int i = 1; i < n; i++) {
        update(ord[i - 1], 1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                int val = depth[u] + (h[v] < h[u]);
                update(v, val);
            }
        }
        ans = min(ans, mx - h[ord[i]]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        solve();
    }

    return 0;
}