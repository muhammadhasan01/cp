#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m;
int deg[N][2];
int dp[N][2];
vector<int> adj[N][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][0].emplace_back(v);
        deg[v][0]++;
        adj[v][1].emplace_back(u);
        deg[u][1]++;
    }
    for (int it = 0; it < 2; it++) {
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (deg[i][it] == 0) {
                q.emplace(i);
            }
        }
        int rem = n;
        while (!q.empty()) {
            int u = q.front();
            if ((int) q.size() == 1) {
                dp[u][it] += rem - 1;
            }
            q.pop();
            for (int v : adj[u][it]) {
                if (--deg[v][it] == 0) {
                    q.emplace(v);
                }
            }
            rem = rem - 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (dp[i][0] + dp[i][1] + 1 == n);
    }
    cout << ans << '\n';

    return 0;
}