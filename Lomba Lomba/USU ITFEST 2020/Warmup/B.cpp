#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int INF = 2e9;

int n;
pair<int, int> p[N];
int dp[N][10];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].first;
    string s;
    cin >> s;
    int res = 0;
    for (auto e : s) {
      if (e == 'A') {
        res += 1;
      } else if (e == 'B') {
        res += 2;
      } else if (e == 'C') {
        res += 4;
      }
    }
    p[i].second = res;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 10; j++) {
      dp[i][j] = INF;
    }
  }
  for (int i = 1; i <= n; i++) {
    dp[i][p[i].second] = p[i].first;
    for (int j = i - 1; j >= 1; j--) {
      for (int k = 1; k < 8; k++) {
        int orz = (k | p[i].second);
        dp[i][orz] = min(dp[i][orz], p[i].first + dp[j][k]);
      }
    }
  }
  int ans = INF;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, dp[i][7]);
  }
  if (ans == INF) ans = -1;
  cout << ans << '\n';

  return 0;
}