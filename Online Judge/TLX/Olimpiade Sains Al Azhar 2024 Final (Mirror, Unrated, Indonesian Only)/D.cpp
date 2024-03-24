#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int D = 2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector g(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    vector dp(n, vector(m, vector<int>(D, INF)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '#') {
                continue;
            }
            if (i == 0 && j == 0) {
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
            }
            if (j > 0 && g[i][j - 1] == '.') {
                dp[i][j][0] = min(dp[i][j][0], dp[i][j - 1][0]);
                dp[i][j][1] = min(dp[i][j][1], 1 + dp[i][j - 1][0]);
            }
            if (i > 0 && g[i - 1][j] == '.') {
                dp[i][j][0] = min(dp[i][j][0], 1 + dp[i - 1][j][1]);
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][1]);
            }
        }
    }
    cout << min(dp[n - 1][m - 1][0], dp[n - 1][m - 1][1]) << '\n';
    
    return 0;
}