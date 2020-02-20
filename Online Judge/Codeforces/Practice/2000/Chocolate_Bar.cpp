#include <bits/stdc++.h>

using namespace std;

const int INF = 1e8;
const int N = 31;
const int K = 51;

int dp[N][N][K];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 1; k < K; k++) {
        dp[i][j][k] = INF;
      }
    }
  }
  for (int i = 1; i < N; i++) {
    for (int j = 1; j < N; j++) {
      for (int k = 1; k <= min(i * j, K - 1); k++) {
        if (i * j == k) {
          dp[i][j][k] = 0;
        } else {
          if (i > 1) {
            int plus = j * j;
            for (int l = 1; l <= k; l++) {
              for (int p = 1; p < i; p++) {
                dp[i][j][k] = min(dp[i][j][k], dp[p][j][l] + dp[i - p][j][k - l] + plus);
              }
            }
          }
          if (j > 1) {
            int plus = i * i;
            for (int l = 1; l <= k; l++) {
              for (int p = 1; p < j; p++) {
                dp[i][j][k] = min(dp[i][j][k], dp[i][p][l] + dp[i][j - p][k - l] + plus);
              }
            }
          }
        }
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int n, m, k;
    cin >> n >> m >> k;
    cout << dp[n][m][k] << '\n';
  }

  return 0;
}