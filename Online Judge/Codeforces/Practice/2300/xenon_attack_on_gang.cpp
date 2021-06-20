#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 5;

int n;
int source;
int par[N][N], sz[N][N];
long long dp[N][N];
vector<int> adj[N];

void dfs(int u, int p) {
    par[source][u] = p;
    sz[source][u] = 1;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
        sz[source][u] += sz[source][v];
    }
}

long long get_dp(int u, int v) {
    if (u == v) {
        return 0;
    }
    if (dp[u][v] != -1) {
        return dp[u][v];
    }
    long long res = 1LL * sz[u][v] * sz[v][u] + max(get_dp(par[v][u], v), get_dp(u, par[u][v]));
    return dp[u][v] = res;
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
    for (int u = 1; u <= n; u++) {
        source = u;
        dfs(u, u);
    }
    memset(dp, -1, sizeof(dp));
    long long ans = 0;
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            ans = max(ans, get_dp(u, v));
        }
    }
    cout << ans << '\n';

    return 0;
}