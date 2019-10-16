#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 4;
const int inf = 1e8;
int n, m, x, y;
char a[N][N];
int pre[N];
int dp[3][N][3], pd[N][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (a[i][j] == '.') pre[j]++;
        }
    }
    for (int it = 1; it <= m; it++) {
        int i = (it & 1);
        pd[i][1] = pd[i][2] = inf;
        for (int j = 1; j <= y; j++) {
            if (j == 1) {
                dp[i][j][1] = pd[i ^ 1][2] + n - pre[it];
                dp[i][j][2] = pd[i ^ 1][1] + pre[it];
            } else if (j <= it) {
                dp[i][j][1] = dp[i ^ 1][j - 1][1] + n - pre[it];
                dp[i][j][2] = dp[i ^ 1][j - 1][2] + pre[it];
            } else if (j > it) {
                break;
            }
            if (j >= x) {
                pd[i][1] = min(pd[i][1], dp[i][j][1]);
                pd[i][2] = min(pd[i][2], dp[i][j][2]);
            }
        }
    }
    int ans = inf;
    for (int j = x; j <= y; j++) {
        if (j > m) break;
        ans = min(ans, dp[m & 1][j][1]);
        ans = min(ans, dp[m & 1][j][2]);
    }
    cout << ans << '\n';

    return 0;
}
