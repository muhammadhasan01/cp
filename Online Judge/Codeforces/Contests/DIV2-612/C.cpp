#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int n;
int a[N];
int dp[N][N][N][2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int odd = (n + 1) / 2;
  int ev = n / 2;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= odd; j++) {
      for (int k = 0; k <= ev; k++) {
        for (int z = 0; z <= 1; z++) {
          dp[i][j][k][z] = N;
          if (z) {
            if (j == 0 || (a[i] > 0 && a[i] % 2 == 0)) {
              continue;
            }
            if (i == 1) {
              dp[i][j][k][z] = 0;
              continue;
            }
            dp[i][j][k][z] = min(dp[i][j][k][z], 1 + dp[i - 1][j - 1][k][0]);
            dp[i][j][k][z] = min(dp[i][j][k][z], dp[i - 1][j - 1][k][1]);
          } else {
            if (k == 0 || (a[i] > 0 && a[i] % 2 == 1)) {
              continue;
            }
            if (i == 1) {
              dp[i][j][k][z] = 0;
              continue;
            }
            dp[i][j][k][z] = min(dp[i][j][k][z], dp[i - 1][j][k - 1][0]);
            dp[i][j][k][z] = min(dp[i][j][k][z], 1 + dp[i - 1][j][k - 1][1]);
          }
        }
      }
    }
  }
  cout << min(dp[n][odd][ev][0], dp[n][odd][ev][1]) << '\n';

  return 0;
}
