#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
int n, t;
double dp[N][N];
double p;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p >> t;
    dp[0][0] = 1;
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = p * (dp[i - 1][j - 1]) + (1.0 - p) * (dp[i - 1][j]);
        }
    }
    double ans = 0;
    for (int i = 1; i <= t; i++) ans += dp[t][i] * (1.0) * min(n, i);
    cout << fixed << setprecision(9) << ans << '\n';

    return 0;
}
