#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

int n, h, l, r;
int a[N];
int dp[N][N];
bool can[N][N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> h >> l >> r;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  can[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < h; j++) {
      if (!can[i - 1][j]) continue;
      int k = (j + a[i]) % h;
      can[i][k] = true;
      dp[i][k] = max(dp[i][k], dp[i - 1][j]);
      if (l <= k && k <= r && can[i - 1][j]) {
        dp[i][k] = max(dp[i][k], dp[i - 1][j] + 1);
      }
    }
    for (int j = 0; j < h; j++) {
      if (!can[i - 1][j]) continue;
      int k = (j + a[i] - 1) % h;
      can[i][k] = true;
      dp[i][k] = max(dp[i][k], dp[i - 1][j]);
      if (l <= k && k <= r && can[i - 1][j]) {
        dp[i][k] = max(dp[i][k], dp[i - 1][j] + 1);
      }
    }
  }
  int ans = 0;
  for (int j = 0; j < h; j++) ans = max(ans, dp[n][j]);
  cout << ans << '\n';

  return 0;
}