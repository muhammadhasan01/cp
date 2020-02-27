#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int M = 2e4 + 5;

int n, m, k;
int a[N][M];
int pre[N][M];
int pref[N][M], suf[N][M];
int dp[N][M];

int get(int x1, int y1, int x2, int y2) {
  return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n + 1; i++) {
    int cur = 0;
    for (int j = 1; j <= m; j++) {
      cur += a[i][j];
      pre[i][j] = cur + pre[i - 1][j];
    }
  }
  for (int j = 1; j <= m - k + 1; j++) {
    dp[1][j] = get(1, j, 2, j + k - 1);
    pref[1][j] = max(pref[1][j - 1], dp[1][j]);
  }
  for (int j = m - k + 1; j >= 1; j--) {
    suf[1][j] = max(suf[1][j + 1], dp[1][j]);
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m - k + 1; j++) {
      int cur = get(i, j, i + 1, j + k - 1);
      dp[i][j] = max(dp[i][j], cur + pref[i - 1][max(0, j - k)]);
      dp[i][j] = max(dp[i][j], cur + suf[i - 1][min(m - k + 2, j + k)]);
      for (int l = max(1, j - k + 1); l <= min(m - k + 1, j + k - 1); l++) {
        int left = max(l, j);
        int right = min(l + k - 1, j + k - 1);
        dp[i][j] = max(dp[i][j], cur + dp[i - 1][l] - get(i, left, i, right));
      }
      pref[i][j] = max(pref[i][j - 1], dp[i][j]);
    }
    for (int j = m - k + 1; j >= 1; j--) {
      suf[i][j] = max(suf[i][j + 1], dp[i][j]);
    }
  }
  cout << suf[n][1] << '\n';

  return 0;
}