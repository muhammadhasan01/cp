#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m;
int col[N];
vector<int> adj[N];
vector<int> answer[2];

void dismiss() {
    cout << -1 << '\n';
    exit(0);
}

void dfs(int u, int p) {
    for (auto v : adj[u]) {
        if (v == p) continue;
        if (col[v] == 0) {
            col[v] = 3 - col[u];
            dfs(v, u);
        } else if (col[v] == col[u])
            dismiss();
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
    for (int i = 1; i <= n; i++) {
        if (col[i]) continue;
        col[i] = 1;
        dfs(i, i);
    }
    vector<int> v[2];
    for (int i = 1; i <= n; i++)
        v[col[i] - 1].emplace_back(i);
    for (int it = 0; it < 2; it++) {
        cout << v[it].size() << '\n';
        for (int x : v[it])
            cout << x << ' ';
        cout << '\n';
    }

    return 0;
}