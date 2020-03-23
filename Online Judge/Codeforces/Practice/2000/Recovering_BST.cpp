#include <bits/stdc++.h>

using namespace std;

const int N = 705;

int n;
int a[N];
bitset<N> dp[N][N];
bitset<2> pd[N][N];
bitset<N> can[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (__gcd(a[i], a[j]) > 1) {
        can[i][j] = 1;
        can[j][i] = 1;
      }
    }
  }
  for (int len = 1; len <= n; len++) {
    for (int i = 1; i <= n; i++) {
      int j = i + len - 1;
      if (j > n) break;
      if (len == 1) {
        dp[i][i][i] = 1;
        pd[i + 1][i][0] = 1;
        pd[i][i - 1][1] = 1;
      } else if (len == 2) {
        dp[i][j][i] = pd[i + 1][j][0] = can[i][j];
        dp[i][j][j] = pd[i][j - 1][1] = can[j][i];
      } else {
        for (int k = i + 1; k <= j; k++) {
          if (can[i][k] == 1 && dp[i + 1][j][k] == 1) {
            dp[i][j][i] = pd[i + 1][j][0] = 1;
            break;
          }
        }
        for (int k = j - 1; k >= i; k--) {
          if (can[k][j] == 1 && dp[i][j - 1][k] == 1) {
            dp[i][j][j] = pd[i][j - 1][1] = 1;
          }
        }
        for (int k = i + 1; k <= j - 1; k++) {
          if (pd[i][k - 1][1] == 1 && pd[k + 1][j][0] == 1) {
            dp[i][j][k] = 1;
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (dp[1][n][i] == 1) {
      cout << "Yes" << '\n';
      return 0;
    }
  }
  cout << "No" << '\n';

  return 0;
}