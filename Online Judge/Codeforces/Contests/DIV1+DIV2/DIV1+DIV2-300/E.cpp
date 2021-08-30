#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int N = 2e5 + 5;

int n;
vector<int> adj[N];
int dp[2][N];

void dfs(int tp, int u, int h) {
    if (adj[u].empty()) {
        dp[tp][u] = 1;
        return;
    }
    if (tp == h) {
        dp[tp][u] = INF;
    }
    for (int v : adj[u]) {
        dfs(tp, v, 1 - h);
        if (tp == 0) {
            if (h == 0) {
                dp[tp][u] = min(dp[tp][u], dp[tp][v]);
            } else if (h == 1) {
                dp[tp][u] += dp[tp][v];
            }
        } else if (tp == 1) {
            if (h == 0) {
                dp[tp][u] += dp[tp][v];
            } else if (h == 1) {
                dp[tp][u] = min(dp[tp][u], dp[tp][v]);
            }
        }
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
    }
    for (int it = 0; it < 2; it++) {
        dfs(it, 1, 0);
    }
    int leaves = 0;
    for (int u = 1; u <= n; u++) {
        if (adj[u].empty()) {
            leaves++;
        }
    }
    cout << leaves - dp[0][1] + 1 << " " << dp[1][1] << '\n';

    return 0;
}