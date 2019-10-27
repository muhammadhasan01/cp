#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;
int n,k;
vector<int> g[N];
int dp[505][N], pre[505][N][2];

void dfs(int u, int p, int i) {
    for (auto v : g[u]) {

        dp[i][u] += pre[i - 1][v][!(i & 1)];
        dp[i][u] -= pre[i - 2][u][i & 1];

        if (v != p) {
            dfs(v, u, i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i <= k; i++) {
        if (i == 0) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = 1;
                pre[i][j][i & 1] = dp[i][j];
            }
        } else if (i == 1) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = g[j].size();
                pre[i][j][i & 1] = dp[i][j];
            }
        } else {
            dfs(1, 1, i);
            for (int j = 1; j <= n; j++) {
                pre[i][j][i & 1] = pre[i - 2][j][i & 1] + dp[i][j];
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (1LL) * dp[k][i];
    }
    cout << ans / 2 << '\n';

    return 0;
}
