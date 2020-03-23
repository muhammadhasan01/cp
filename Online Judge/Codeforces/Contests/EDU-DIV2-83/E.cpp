#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n;
int a[N];
int dp[N][N];
int best[N][N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i][i] = a[i];
    best[i][i] = 1;
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i <= n; i++) {
      int j = i + len - 1;
      if (j > n) break;
      if (len == 2) {
        dp[i][j] = (a[i] == a[j] ? a[i] + 1 : 0);
        best[i][j] = (dp[i][j] > 0 ? 1 : 2);
      } else {
        best[i][j] = j - i + 1;
        for (int k = i; k <= j - 1; k++) {
          if (dp[i][k] != 0) dp[i][j] = (dp[i][k] == dp[k + 1][j] ? dp[i][k] + 1 : 0);
          best[i][j] = min(best[i][j], best[i][k] + best[k + 1][j]);
          if (dp[i][j] > 0) {
            best[i][j] = 1;
            break;
          }
        }
      }
    }
  }
  cout << best[1][n] << '\n';

  return 0;
}