#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n, m, p;
long long a[N][N], b[N][N];
long long pos[N][N];
long long dp[N][N];

void dismiss() {
  cout << "TIDAK" << '\n';
  exit(0);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> p;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      b[i][j] = a[i][j];
    }
  }
  for (int i = 1; i <= n - p + 1; i++) {
    long long pre = 0;
    for (int j = 1; j <= m - p + 1; j++) {
      pre += pos[i][j];
      dp[i][j] = pre + dp[i - 1][j];
      a[i][j] -= dp[i][j];
      if (a[i][j] > 0) {
        pos[i][j] += a[i][j];
        pos[i][j + p] -= a[i][j];
        pos[i + p][j] -= a[i][j];
        pos[i + p][j + p] += a[i][j];
        pre += a[i][j];
        dp[i][j] += a[i][j];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    long long pre = 0;
    for (int j = 1; j <= m; j++) {
      pre += pos[i][j];
      dp[i][j] = pre + dp[i - 1][j];
      if (dp[i][j] != b[i][j]) dismiss();
    }
  }
  cout << "YA" << '\n';

  return 0;
}
