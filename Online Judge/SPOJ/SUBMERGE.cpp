#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int M = 1e5 + 5;
int n, m;
vector<int> g[N];
int tin[N], low[N], timer, children, ans;
bool vis[N], cut[N];

void reset() {
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        tin[i] = low[i] = 0;
        vis[i] = cut[i] = false;
    }
    timer = ans = 0;
}

void dfs(int u, int p = -1) {
    vis[u] = true;
    tin[u] = low[u] = ++timer;
    int children = 0;
    for (auto v : g[u]) {
        if (v == p) continue;
        if (vis[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= tin[u] && p != -1) {
                cut[u] = true;
            }
            children++;
        }
    }
    if (p == -1 && children > 1) {
        cut[u] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        reset();
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) dfs(i);
        }
        for (int i = 1; i <= n; i++) {
            if (cut[i]) ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}
