#include <bits/stdc++.h>

using namespace std;

const long long INF = 4e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    long long a, b, c;
    cin >> n >> a >> b >> c;
    vector<vector<long long>> d(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }

    auto getDist = [&](int s, long long mul, long long add) -> vector<long long> {
        vector<long long> dist(n, INF);
        vector<bool> vis(n);
        dist[s] = 0;
        for (int i = 0; i < n; i++) {
            int u = -1;
            for (int j = 0; j < n; j++) {
                if (vis[j]) {
                    continue;
                }
                if (u == -1 || (dist[j] < dist[u])) {
                    u = j;
                }
            }
            if (u == -1 || dist[u] == INF) {
                break;
            }
            vis[u] = true;
            for (int v = 0; v < n; v++) {
                if (dist[v] > dist[u] + d[u][v] * mul + add) {
                    dist[v] = dist[u] + d[u][v] * mul + add;
                }
            }
        }
        return dist;
    };

    vector<long long> distS = getDist(0, a, 0);
    vector<long long> distE = getDist(n - 1, b, c);

    long long ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        ans = min(ans, distS[i] + distE[i]);
    }
    cout << ans << '\n';
    
    return 0;
}