#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
bool c[N], vis[N];
int cmp;
int comp[N];
vector<int> g[N];
vector<int> gc[N];
int dp[N];
int diameter;

void dfs(int u, int p) {
    if (vis[u]) return;
    if (c[u] != c[p]) return;
    vis[u] = 1;
    comp[u] = cmp;
    for (auto v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}

void DFS(int u, int p) {
    int maksOne = 0, maksTwo = 0;
    for (auto v : gc[u]) {
        if (v == p) continue;
        DFS(v, u);
        maksTwo = max(maksTwo, dp[v]);
        if (maksTwo > maksOne) swap(maksOne, maksTwo);
    }
    dp[u] = 1 + maksOne;
    diameter = max(diameter, maksOne + maksTwo);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ++cmp;
            dfs(i, i);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto j : g[i]) {
            if (comp[j] == comp[i]) continue;
            gc[comp[i]].push_back(comp[j]);
        }
    }
    DFS(1, 1);
    cout << (diameter + 1) / 2 << '\n';

    return 0;
}