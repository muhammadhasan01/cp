#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
vector<pair<int, int>> adj[N];
int ans[N];

void dfs(int u, int p, int col) {
    ans[u] = col;
    for (auto e : adj[u]) {
        int v, w;
        tie(v, w) = e;
        if (v == p) continue;
        int res_col = (w & 1 ? 1 - col : col);
        dfs(v, u, res_col);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, (w & 1));
        adj[v].emplace_back(u, (w & 1));
    }
    dfs(1, 1, 1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}