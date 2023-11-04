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
    vector<vector<long long>> dp(m + 1, vector<long long>(k + 1, INF));
    {
        if (c[1] > 0) {
            dp[c[1]][1] = 0;
        } else {
            for (int col = 1; col <= m; col++) {
                dp[col][1] = p[1][col];
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        int L = (c[i] > 0 ? c[i] : 1);
        int R = (c[i] > 0 ? c[i] : m);
        vector<vector<long long>> ndp(m + 1, vector<long long>(k + 1, INF));
        for (int col = L; col <= R; col++) {
            int cost = (c[i] > 0 ? 0 : p[i][col]);
            for (int beauty = 1; beauty <= k; beauty++) {
                ndp[col][beauty] = min(ndp[col][beauty], dp[col][beauty] + cost);
                for (int color = 1; color <= m; color++) {
                    if (color == col) {
                        continue;
                    }
                    ndp[col][beauty] = min(ndp[col][beauty], dp[color][beauty - 1] + cost);
                }
            }
        }
        dp.swap(ndp);
    }
    long long ans = INF;
    for (int col = 1; col <= m; col++) {
        ans = min(ans, dp[col][k]);
    }
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << '\n';
    
    return 0;
}