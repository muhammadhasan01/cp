#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;

int n, m;
char a[N], b[N];
int dp[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = 2 + max(0, dp[i - 1][j - 1]);
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) - 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';

    return 0;
}