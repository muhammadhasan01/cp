#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
short int n, a[N][N][3], dp[N][N][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x == 0) {
                a[i][j][1] = a[i][j][2] = -1;
            } else {
                int temp = x, k1 = 0, k2 = 0;
                while (temp % 2 == 0) {
                    temp /= 2;
                    k1++;
                }
                temp = x;
                while (temp % 5 == 0) {
                    temp /= 5;
                    k2++;
                }
                a[i][j][1] = k1;
                a[i][j][2] = k2;
            }
        }
    }

    for (int t = 1; t <= 2; t++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) {
                    dp[i][j][t] = a[i][j][t];
                } else if (i == 1) {
                    if (dp[i][j - 1][t] == -1 || a[i][j][t] == -1) {
                        dp[i][j][t] = -1;
                    } else {
                        dp[i][j][t] = a[i][j][t] + dp[i][j - 1][t];
                    }
                } else if (j == 1) {
                    if (dp[i - 1][j][t] == -1 || a[i][j][t] == -1) {
                        dp[i][j][t] = -1;
                    } else {
                        dp[i][j][t] = a[i][j][t] + dp[i - 1][j][t];
                    }
                } else {
                    if (a[i][j][t] == -1) {
                        dp[i][j][t] = -1;
                    } else if (dp[i - 1][j][t] == -1 && dp[i][j - 1][t] == -1) {
                        dp[i][j][t] = -1;
                    } else if (dp[i - 1][j][t] == -1) {
                        if (dp[i][j - 1][t] + a[i][j][t] == 0) {
                            dp[i][j][t] = 0;
                        } else {
                            dp[i][j][t] = -1;
                        }
                    } else if (dp[i][j - 1][t] == -1) {
                        if (dp[i - 1][j][t] + a[i][j][t] == 0) {
                            dp[i][j][t] = 0;
                        } else {
                            dp[i][j][t] = -1;
                        }
                    } else {
                        dp[i][j][t] = a[i][j][t] + min(dp[i - 1][j][t], dp[i][j - 1][t]);
                    }
                }
            }
        }
    }

    int k = 1;
    char ans[2 * n];
    if (abs(dp[n][n][1]) > abs(dp[n][n][2])) k = 2;
    int cnt = 0;
    if (dp[n][n][k] == -1) {
        cout << -dp[n][n][k] << "\n";
        int i = n, j = n;
        while (i != 1 || j != 1) {
            if (i == 1 || (j > 1 && dp[i][j - 1][k] == -1)) {
                ans[cnt++] = 'R';
                j--;
            } else if (j == 1 || (i > 1 && dp[i - 1][j][k] == -1)) {
                ans[cnt++] = 'D';
                i--;
            } else if (a[i][j][k] == -1) {
                ans[cnt++] = 'D';
                i--;
            } else if (i == 1 || (j > 1 && dp[i][j - 1][k] + a[i][j][k] == dp[i][j][k])) {
                ans[cnt++] = 'R';
                j--;
            } else if (j == 1 || (i > 1 && dp[i - 1][j][k] + a[i][j][k] == dp[i][j][k])) {
                ans[cnt++] = 'D';
                i--;
            }
        }
    } else if (dp[n][n][k] == 0){
        cout << dp[n][n][k] << '\n';
        int i = n, j = n;
        while (i != 1 || j != 1) {
            if (i == 1 || (j > 1 && dp[i][j - 1][k] == 0)) {
                ans[cnt++] = 'R';
                j--;
            } else if (j == 1 || (i > 1 && dp[i - 1][j][k] == 0)) {
                ans[cnt++] = 'D';
                i--;
            }
        }
    } else {
        cout << dp[n][n][k] << '\n';
        int i = n, j = n;
        while (i != 1 || j != 1) {
            if (i == 1 || (j > 1 && dp[i][j - 1][k] + a[i][j][k] == dp[i][j][k])) {
                ans[cnt++] = 'R';
                j--;
            } else if (j == 1 || (i > 1 && dp[i - 1][j][k] + a[i][j][k] == dp[i][j][k])) {
                ans[cnt++] = 'D';
                i--;
            }
        }
    }
    for (int i = cnt - 1; i >= 0; i--) {
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}
