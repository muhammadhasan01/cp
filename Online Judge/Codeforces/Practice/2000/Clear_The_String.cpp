#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 5;
int n;
char a[N];
int dp[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n; i++) {
            int j = i + len - 1;
            if (j > n) break;
            if (len == 1) {
                dp[i][j] = 1;
            } else if (len == 2) {
                dp[i][j] = (a[i] == a[j] ? 1 : 2);
            } else {
                dp[i][j] = n + 5;
                for (int t = i; t <= j - 1; t++) {
                    int cur = dp[i][t] + dp[t + 1][j];
                    if (a[t] == a[t + 1] || a[i] == a[t + 1] || a[t] == a[j]) cur--;
                    dp[i][j] = min(dp[i][j], cur);
                }
                if (a[i] == a[j]) dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + 1);
            }
        }
    }
    cout << dp[1][n] << '\n';

    return 0;
}
