#include <bits/stdc++.h>

using namespace std;

const int M = 2e3;
int n, q;
int l, r;
int dp[M + 5][M + 5];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l >> r;
    dp[l][r]++;
  }
  for (int len = M; len >= 1; len--) {
    for (int i = 1; i <= M; i++) {
      int j = len + i - 1;
      if (j > M) break;
      dp[i][j] += dp[i - 1][j] + dp[i][j + 1] - dp[i - 1][j + 1];
    }
  }
  cin >> q;
  while (q--) {
    cin >> l >> r;
    cout << dp[l][r] << '\n';
  }

  return 0;
}
