#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int tc;
vector<int> g[N];
short int k[N][N];
short int vis[N];
int n, m;

bool dfs(int u, int p) {
    vis[u] = 1;
    for (auto v : g[u]) {
        if (p == v) continue;
        if (vis[v] == 1) {
            return true;
        } else {
            if (dfs(v, u)) return true;
        }
    }
    vis[u] = 2;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        memset(k, 0, sizeof(k));
        fill(vis + 1, vis + 1 + n, 0);
        for (int i = 1; i <= n; i++) g[i].clear();
        bool cycle = false;
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            u++, v++;
            if (u == v) cycle = true;
            else if (k[u][v]) cycle = true;
            g[u].push_back(v);
            g[v].push_back(u);
            k[u][v] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                cycle |= dfs(i, i);
            }
            if (cycle) break;
        }
        puts(cycle ? "1" : "0");
    }

    return 0;
}
