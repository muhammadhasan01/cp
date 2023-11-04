#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n;
vector<int> adj[N];
long long dp[N][2]; // (node, white / black)
long long sum[N];

void dfs(int u, int p) {
    dp[u][0] = dp[u][1] = 1;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
    }
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        dp[u][0] = (dp[u][0] * sum[v]) % MOD;
        dp[u][1] = (dp[u][1] * dp[v][0]) % MOD;
    }
    sum[u] = (dp[u][0] + dp[u][1]) % MOD;
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
    cout << sum[1] << '\n';

    return 0;
}