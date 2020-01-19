#include <bits/stdc++.h>

using namespace std;

const long long M = 1e9 + 7;

const int N = 1e3 + 5;

int n, m;
long long dp[15][N];
long long pre[15][N];
long long ans = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == 1) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = pre[i - 1][j] % M;
      }
      pre[i][j] = (pre[i][j - 1] + dp[i][j]) % M;
    }
  }
  for (int i = 1; i <= n; i++) {
    ans = (ans + dp[m][i] * pre[m][n - i + 1]) % M;
  }
  cout << (ans % M + M) % M << '\n';

  return 0;
}
