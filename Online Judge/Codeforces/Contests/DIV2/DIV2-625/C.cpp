#include <bits/stdc++.h>

using namespace std;

const int N = 105;

string s;
int n;
int a[N];
int dp[N][N];
int best[N][N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    a[i] = (int) (s[i] - 'a') + 1;
  }
  for (int len = 1; len <= n; len++) {
    for (int i = 0; i < n; i++) {
      int j = i + len - 1;
      if (j >= n) break;
      if (len == 1) {
        dp[i][j] = a[i];
        best[i][j] = 1;
      } else if (len == 2) {
        if (abs(a[i] - a[j]) == 1) {
          dp[i][j] = min(a[i], a[j]);
          best[i][j] = 1;
        } else {
          dp[i][j] = -1;
          best[i][j] = 2;
        }
      } else {
        best[i][j] = j - i + 1;
        dp[i][j] = -1;
        for (int k = i; k <= j - 1; k++) {
          best[i][j] = min(best[i][j], best[i][k] + best[k + 1][j]);
          if (abs(dp[i][k] - dp[k + 1][j]) == 1) {
            best[i][j] = 1;
            dp[i][j] = min(dp[i][k], dp[k + 1][j]);
            break;
          }
        }
      }
    }
  }
  cout << n - best[0][n - 1] << '\n';

  return 0;
}