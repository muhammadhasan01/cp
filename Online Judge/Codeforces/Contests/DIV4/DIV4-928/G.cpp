#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        --p;
        adj[p].emplace_back(i);
    }
    vector<char> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector dp(n, vector<int>(3, INF));

    function<void(int)> dfs = [&](int u) {
        for (int v : adj[u]) {
            dfs(v);
        }
        if (c[u] == 'S') {
            dp[u][0] = 0;
            for (int v : adj[u]) {
                dp[u][0] += min({dp[v][0], dp[v][1] + 1, dp[v][2]});
            }
        } else if (c[u] == 'P') {
            dp[u][1] = 0;
            for (int v : adj[u]) {
                dp[u][1] += min({dp[v][0] + 1, dp[v][1], dp[v][2]});
            }
        } else if (c[u] == 'C') {
            for (int x : {0, 1}) {
                int len = (int) adj[u].size();
                vector<int> pre(len);
                int y = (x ^ 1);
                for (int i = 0; i < len; i++) {
                    int v = adj[u][i];
                    pre[i] = min({dp[v][x], dp[v][y] + 1, dp[v][2]});
                    if (i > 0) {
                        pre[i] += pre[i - 1];
                    }
                }
                for (int i = 0; i < len; i++) {
                    int v = adj[u][i];
                    int L = (i > 0 ? pre[i - 1] : 0);
                    int R = (i + 1 < len ? pre[len - 1] - pre[i] : 0);
                    dp[u][x] = min(dp[u][x], L + dp[v][x] + R);
                }
            }
            dp[u][2] = 0;
            for (int v : adj[u]) {
                dp[u][2] += min({dp[v][0] + 1, dp[v][1] + 1, dp[v][2]});
            }
        }
    };

    dfs(0);

    cout << min({dp[0][0], dp[0][1], dp[0][2]}) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}