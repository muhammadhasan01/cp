#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, m;
int cnt[N];
int dp[N][5][5];
int ans;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  for (int i = 1; i <= m; i++) {
    for (int s = 0; s < 3; s++) {
      for (int m = 0; m < 3; m++) {
        for (int e = 0; e < 3; e++) {
          if (cnt[i] >= s + m + e && cnt[i + 1] >= m + e && cnt[i + 2] >= e) {
            dp[i][m][e] = max(dp[i][m][e], dp[i - 1][s][m] + (cnt[i] - s - m - e) / 3 + e);
          }
          ans = max(ans, dp[i][m][e]);
        }
      }
    }
  }
  cout << ans << '\n';

  return 0;
}