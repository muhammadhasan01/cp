#include <bits/stdc++.h>

using namespace std;

const int B = 62;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> cnt(B);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < B; j++) {
            if (a[i] & (1LL << j)) {
                if (++cnt[j] == 3) {
                    cout << 3 << '\n';
                    return 0;
                }
            }
        }
    }
    vector<long long> b;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) {
            b.emplace_back(a[i]);
        }
    }
    int m = (int) b.size();
    vector<vector<int>> adj(m);
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (b[i] & b[j]) {
                adj[i].emplace_back(j);
                adj[j].emplace_back(i);
            }
        }
    }

    auto solve = [&](int U, int V) -> int {
        vector<int> dist(m, -1);
        queue<int> q;
        q.emplace(U);
        dist[U] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (u == U && v == V) {
                    continue;
                }
                if (u == V && v == U) {
                    continue;
                }
                if (dist[v] == -1) {
                    dist[v] = 1 + dist[u];
                    q.emplace(v);
                }
            }
        }
        if (dist[V] == -1) {
            return INT_MAX;
        }
        return dist[V] + 1;
    };

    int ans = INT_MAX;
    for (int u = 0; u < m; u++) {
        for (int v : adj[u]) {
            ans = min(ans, solve(u, v));
        }
    }
    if (ans == INT_MAX) {
        ans = -1;
    }
    cout << ans << '\n';
    
    return 0;
}