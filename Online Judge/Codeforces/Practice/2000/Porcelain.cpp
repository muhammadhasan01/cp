#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;
const int M = 1e4 + 5;
const int INF = 1e9;

int n, m;
int a[N][N];
int pre[N][N];
int dp[N][M];
int lenz[N];
int sum, cnt;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> lenz[i];
    for (int j = 1; j <= lenz[i]; j++) {
      cin >> a[i][j];
      a[i][j] += a[i][j - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    pre[i][0] = 0;
    for (int len = 1; len <= lenz[i]; len++) {
      pre[i][len] = INF;
      for (int j = len; j <= lenz[i]; j++) {
        pre[i][len] = min(pre[i][len], a[i][j] - a[i][j - len]);
      }
    }
    sum += a[i][lenz[i]];
    cnt += lenz[i];
  }
  m = cnt - m;
  for (int j = 0; j <= m; j++) dp[1][j] = (j > lenz[1] ? INF : pre[1][j]);
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i][j] = INF;
      for (int k = 0; k <= lenz[i]; k++) {
        if (j - k < 0) break;
        dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + pre[i][k]);
      }
    }
  }
  cout << sum - dp[n][m] << '\n';

  return 0;
}