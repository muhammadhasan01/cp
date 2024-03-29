#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
int n;
short int a[N];
short int dp[N][N][3];
const int inf = 30000;

short int min(short int a, short int b) {
    return (a < b ? a : b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j][1] = dp[i][j][2] = (i == j ? 0 : inf);
        }
    }
    for (int j = 1; j <= n; j++) {
        for (int i = j; i >= 1; i--) {
            dp[i - 1][j][1] = min(dp[i - 1][j][1], dp[i][j][1] + int(a[i] != a[i - 1]));
            dp[i - 1][j][1] = min(dp[i - 1][j][1], dp[i][j][2] + int(a[j] != a[i - 1]));
            dp[i][j + 1][2] = min(dp[i][j + 1][2], dp[i][j][1] + int(a[i] != a[j + 1]));
            dp[i][j + 1][2] = min(dp[i][j + 1][2], dp[i][j][2] + int(a[j] != a[j + 1]));
        }
    }
    cout << min(dp[1][n][1], dp[1][n][2]) << '\n';

    return 0;
}
