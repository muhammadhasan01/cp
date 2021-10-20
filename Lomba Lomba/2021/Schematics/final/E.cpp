#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m;
vector<int> adj[N];
int col[N];

void dfs(int u, int p, int c) {
    col[u] = c;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (col[v] == -1) {
            dfs(v, u, 1 - c);
        } else if (col[v] == col[u]) {
            cout << "Ya" << '\n';
            exit(0);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    memset(col, -1, sizeof(col));
    for (int u = 1; u <= n; u++) {
        if (col[u] == -1) {
            dfs(u, u, 1);
        }
    }
    cout << "Tidak" << '\n';

    return 0;
}