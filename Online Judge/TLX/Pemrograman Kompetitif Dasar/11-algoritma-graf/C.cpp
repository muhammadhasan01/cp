#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);   
    }
    for (int u = 1; u <= n; u++) {
        dist[u][u] = 0;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    long long ans = 0;
    int lastNode = -1;
    while (q--) {
        int u;
        cin >> u;
        if (lastNode != -1) {
            ans += dist[lastNode][u];
        }
        lastNode = u;
    }
    cout << ans << '\n';
    
    return 0;
}