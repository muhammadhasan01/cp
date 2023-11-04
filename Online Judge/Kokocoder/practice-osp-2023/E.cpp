#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    vector<vector<int>> p(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> p[i][j];
        }
    }
    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(m + 1, vector<long long>(k + 1, INF)));
    {
        if (c[1] > 0) {
            dp[1][c[1]][1] = 0;
        } else {
            for (int col = 1; col <= m; col++) {
                dp[1][col][1] = p[1][col];
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        int L = (c[i] > 0 ? c[i] : 1);
        int R = (c[i] > 0 ? c[i] : m);
        for (int col = L; col <= R; col++) {
            int cost = (c[i] > 0 ? 0 : p[i][col]);
            for (int beauty = 1; beauty <= k; beauty++) {
                if (dp[i - 1][col][beauty] != INF) {
                    dp[i][col][beauty] = min(dp[i][col][beauty], dp[i - 1][col][beauty] + cost);
                }
                for (int color = 1; color <= m; color++) {
                    if (color == col) {
                        continue;
                    }
                    if (dp[i - 1][color][beauty - 1] != INF) {
                        dp[i][col][beauty] = min(dp[i][col][beauty], dp[i - 1][color][beauty - 1] + cost);
                    }
                }
            }
        }
    }
    long long ans = INF;
    for (int col = 1; col <= m; col++) {
        ans = min(ans, dp[n][col][k]);
    }
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << '\n';
    
    return 0;
}