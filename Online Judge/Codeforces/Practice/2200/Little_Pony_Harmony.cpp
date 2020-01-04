#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;
const int M = 1 << 17;
const int INF = 2e9;

int n;
int a[N];
int mp[N], inv[N];
int dp[N][M], best[N][M], pre[N][M];
int mask[N], tot;
bool prime[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 2; i <= 60; i++) {
    if (prime[i] == 0) {
      mp[i] = tot;
      inv[tot++] = i;
      for (int j = i * i; j <= 60; j += i) prime[j] = 1;
    }
  }
  for (int i = 2; i <= 60; i++) {
    int k = i;
    for (int j = 2; j <= i; j++) {
      if (k % j == 0) {
        mask[i] |= (1 << mp[j]);
        while (k % j == 0) k /= j;
      }
    }
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < M; j++) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 60; j++) {
      int x = (~ mask[j]) & (M - 1);
      for (int s = x; s >= 0; s = (s - 1) & x) {
        if (dp[i][s | mask[j]] > dp[i - 1][s] + abs(a[i] - j)) {
          dp[i][s | mask[j]] = dp[i - 1][s] + abs(a[i] - j);
          best[i][s | mask[j]] = j;
          pre[i][s | mask[j]] = s;
        }
        if (s == 0) break;
      }
    }
  }
  int res = INF, tg = 0;
  for (int i = 0; i < M; i++) {
    if (res > dp[n][i]) {
      res = dp[n][i];
      tg = i;
    }
  }
  deque<int> ans;
  for (int i = n; i >= 1; i--) {
    ans.push_front(best[i][tg]);
    tg = pre[i][tg];
  }
  for (auto e : ans) cout << e << " ";
  cout << '\n';

  return 0;
}
