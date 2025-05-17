#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n + 1);
    queue<int> q;
    vector<int> dist(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        int x = i - a[i];
        if (x >= 1) {
            if (a[i] % 2 != a[x] % 2) {
                dist[i] = 1;
                q.emplace(i);
            } else {
                adj[x].emplace_back(i);
            }
        }
        int y = i + a[i];
        if (y <= n) {
            if (a[i] % 2 != a[y] % 2) {
                dist[i] = 1;
                q.emplace(i);
            } else {
                adj[y].emplace_back(i);
            }
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.emplace(v);
            }
        }
    }
    for (int u = 1; u <= n; u++) {
        cout << dist[u] << " \n"[u == n];
    }
    
    return 0;
}