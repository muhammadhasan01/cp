#include <bits/stdc++.h>

using namespace std;

const int N = 305;

int n, q;
int dp[N][N];
long long ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> dp[i][j];
      ans += (1LL) * dp[i][j];
    }
  }
  cin >> q;
  while (q--) {
    int u, v, w;
    cin >> u >> v >> w;
    if (w >= dp[u][v]) {
      cout << ans / 2 << " ";
      continue;
    }
    ans = 0;
    dp[u][v] = dp[v][u] = w;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = min(dp[i][j], dp[i][u] + dp[u][v] + dp[v][j]);
        dp[i][j] = min(dp[i][j], dp[i][v] + dp[v][u] + dp[u][j]);
        ans += (1LL) * dp[i][j];
      }
    }
    cout << ans / 2 << " ";
  }
  cout << '\n';

  return 0;
}
