#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;
const int INF = 2e9;

int n;
int min_mx = INF;
int center = -1;
int sz[N];
bool ans[N];
vector<int> adj[N];
vector<pair<int, int>> subtrees;

void dfs(int u, int p) {
    sz[u] = 1;
    int mx = -1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        mx = max(mx, sz[v]);
    }
    mx = max(mx, n - sz[u]);
    if (mx < min_mx) {
        min_mx = mx;
        center = u;
    }
}

void rec(int u, int p, int sum_other, int cur) {
    if (sum_other <= n / 2) {
        ans[u] = 1;
    }
    for (int i = 0; i < min(2, (int) subtrees.size()); i++) {
        auto [c, v] = subtrees[i];
        if (v == cur) continue;
        if (n - sz[u] - c <= n / 2) {
            ans[u] = 1;
        }
    }
    for (int v : adj[u]) {
        if (v == p) continue;
        rec(v, u, sum_other, cur);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1, 1);
    dfs(center, center);
    ans[center] = 1;
    for (int u : adj[center]) {
        subtrees.emplace_back(sz[u], u);
    }
    sort(subtrees.rbegin(),subtrees.rend());
    for (int u : adj[center]) {
        rec(u, center, n - sz[u], u);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }

    return 0;
}