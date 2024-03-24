#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector edge(n, vector<long long>(n, INF));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edge[u][v] = w;
    }
    for (int k = 0; k < n; k++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (edge[u][k] == INF || edge[k][v] == INF) {
                    continue;
                }
                edge[u][v] = min(edge[u][v], edge[u][k] + edge[k][v]);
            }
        }
    }
    int all = (1 << n) - 1;
    vector dist(all + 1, vector<long long>(n, INF));
    for (int mask = 1; mask <= all; mask++) {
        vector<int> bits;
        for (int u = 0; u < n; u++) {
            if (mask & (1 << u)) {
                bits.emplace_back(u);
            }
        }
        int len = (int) bits.size();
        if (len == 1) {
            dist[mask][bits[0]] = 0;
            continue;
        }
        for (int i = 0; i < len; i++) {
            int u = bits[i];
            for (int j = 0; j < len; j++) {
                int v = bits[j];
                if (edge[u][v] == INF) {
                    continue;
                }
                int cmask = mask ^ (1 << v);
                if (dist[cmask][u] == INF) {
                    continue;
                }
                dist[mask][v] = min(dist[mask][v], dist[cmask][u] + edge[u][v]);
            }
        }
    }
    long long ans = INF;
    for (int u = 0; u < n; u++) {
        ans = min(ans, dist[all][u]);
    }
    if (ans == INF) {
        cout << "No" << '\n';
        return 0;
    }
    cout << ans << '\n';

    return 0;
}