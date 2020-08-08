#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

int n, m;
char a[N][N];
int dp[N][N][2];
int part[N][N][2];
long long ans = 0;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j][0] = (a[i][j] == a[i - 1][j] ? 1 + dp[i - 1][j][0] : 1);
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            dp[i][j][1] = (a[i][j] == a[i + 1][j] ? 1 + dp[i + 1][j][1] : 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != a[i][j - 1]) {
                part[i][j][0] = 1;   
                continue;
            }
            int cur = min(dp[i][j][0], dp[i][j][1]);
            int mini = min(min(j, m - j + 1), min(i, n - i + 1));
            cur = min(mini, cur);
            if (cur > part[i][j - 1][0]) {
                cur = min(mini, part[i][j - 1][0] + 1);
            }
            part[i][j][0] = cur;
        }
        for (int j = m; j >= 1; j--) {
            if (a[i][j] != a[i][j + 1]) {
                part[i][j][1] = 1;
                continue;
            }
            int cur = min(dp[i][j][0], dp[i][j][1]);
            int mini = min(min(j, m - j + 1), min(i, n - i + 1));
            cur = min(mini, cur);
            if (cur > part[i][j + 1][1]) {
                cur = min(mini, part[i][j + 1][1] + 1);
            }
            part[i][j][1] = cur;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cur = min(part[i][j][0], part[i][j][1]);
            ans += (1LL) * cur;
        }
    }
    cout << ans << '\n';

    return 0;
}