#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;
const int K = 1e5;
const int M = 2 * K + 100;
const int INF = 1e7;

int n, k;
int a[N], b[N];
int dp[N][M];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    b[i] = b[i] * k;
  }
  for (int bal = -K; bal <= K; bal++) dp[0][bal + K] = -INF;
  dp[0][K] = 0;
  for (int i = 1; i <= n; i++) {
    int dif = a[i] - b[i];
    for (int bal = -K; bal <= K; bal++) {
      int j = bal + K;
      dp[i][j] = dp[i - 1][j];
    }
    for (int bal = -K; bal <= K; bal++) {
      int j = bal + K;
      if (dif + j < 0) continue;
      if (dif + j > 2 * K) break;
      dp[i][dif + j] = max(dp[i][dif + j], dp[i - 1][j] + a[i]);
    }
  }
  int ans = dp[n][K];
  if (ans <= 0) ans = -1;
  cout << ans << '\n';

  return 0;
}
