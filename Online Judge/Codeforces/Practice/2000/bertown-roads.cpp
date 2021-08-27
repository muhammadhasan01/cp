#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m;
vector<int> adj[N];
int tin[N], low[N], tim = 0;
bool vis[N];
int par[N];

void dismiss() {
    cout << 0 << '\n';
    exit(0);
}

void dfs(int u, int p = -1) {
    vis[u] = true;
    tin[u] = low[u] = ++tim;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (vis[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            par[v] = u;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (tin[u] < low[v]) {
                dismiss();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    vector<pair<int, int>> ans(m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        ans[i - 1] = make_pair(u, v);
    }
    dfs(1);
    for (auto& [u, v] : ans) {
        int x = u, y = v;
        if (tin[x] > tin[y]) {
            swap(x, y);
        }
        if (par[y] != x) {
            swap(x, y);
        }
        cout << x << ' ' << y << '\n';
    }

    return 0;
}