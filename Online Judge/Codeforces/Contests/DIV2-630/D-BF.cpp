#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n, m;
int a[N][N];
int dp[N][N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  dp[0][1] = a[1][1];
  cout << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = max((dp[i - 1][j] & a[i][j]), (dp[i][j - 1] & a[i][j]));
      cout << dp[i][j] << (j == m ? '\n' : ' ');
    }
  }
  // cout << dp[n][m] << '\n';

  return 0;
}