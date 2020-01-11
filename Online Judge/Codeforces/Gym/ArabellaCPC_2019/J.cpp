#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;

string s;
int n, a[N], ans;
int dp[N][15];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  n = s.length();
  for (int i = n; i >= 1; i--) {
    a[i] = (int) (s[i - 1] - '0');
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= 10; j++) {
      dp[i][j] = INF;
      if (i == 0) {
        dp[i][j] = j;
      } else {
        dp[i][j] = min(dp[i - 1][a[i - 1]] + j, dp[i - 1][a[i - 1] + 1] + 10 - j);
      }
    }
  }
  cout << dp[n][a[n]] << '\n';

  return 0;
}
