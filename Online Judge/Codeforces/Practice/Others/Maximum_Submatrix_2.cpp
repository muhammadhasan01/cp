#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
int n, m;
int dp[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int first = m, last = -1;
        for (int j = 1; j <= m; j++) {
            char x;
            cin >> x;
            if (x == '1') {
                first = min(j, first);
                last = j;
            } else if (last != -1) {
                dp[first][last]++;
                first = m, last = -1;
            }
        }
        if (last != -1) dp[first][last]++;
    }
    int ans = 0;
    for (int len = m; len >= 1; len--) {
        for (int i = 1; i <= m; i++) {
            int j = i + len - 1;
            if (j > m) break;
            dp[i][j] += dp[i - 1][j] + dp[i][j + 1] - dp[i - 1][j + 1];
            ans = max(ans, (j - i + 1) * dp[i][j]);
        }
    }
    cout << ans << '\n';

    return 0;
}
