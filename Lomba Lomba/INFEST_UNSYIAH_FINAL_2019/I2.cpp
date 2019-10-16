#include <bits/stdc++.h>
using namespace std;

int n, m, q;
const long long inf = 2e18;
vector<vector<long long>> g;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    g.resize(n + 3);
    for (int i = 1; i <= n; i++) {
        g[i].resize(n + 3, inf);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        long long x;
        cin >> u >> v >> x;
        u++, v++;
        g[u][v] = min(g[u][v], x);
    }

    for (int i = 1; i <= n; i++) {
        g[i][i] = 0;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        u++, v++;
        if (g[u][v] == inf) g[u][v] = -1;
        cout << g[u][v] << '\n';
    }

    return 0;
}
