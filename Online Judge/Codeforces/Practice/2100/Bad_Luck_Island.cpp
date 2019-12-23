#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int r, s, p;
double dp[N][N][N], ans[4];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> r >> s >> p;
  dp[r][s][p] = 1.0;
  for (int i = r; i >= 0; i--) {
    for (int j = s; j >= 0; j--) {
      for (int k = p; k >= 0; k--) {
        double cur = i * j + j * k + k * i;
        if (i && j) dp[i][j - 1][k] += (1.0 * i * j / cur) * dp[i][j][k];
        if (j && k) dp[i][j][k - 1] += (1.0 * j * k / cur) * dp[i][j][k];
        if (k && i) dp[i - 1][j][k] += (1.0 * k * i / cur) * dp[i][j][k];
       }
    }
  }
  for (int i = 1; i <= r; i++) ans[1] += dp[i][0][0];
  for (int j = 1; j <= s; j++) ans[2] += dp[0][j][0];
  for (int k = 1; k <= p; k++) ans[3] += dp[0][0][k];
  cout << fixed << setprecision(12) << ans[1] << " " << ans[2] << " " << ans[3] << '\n';

  return 0;
}
