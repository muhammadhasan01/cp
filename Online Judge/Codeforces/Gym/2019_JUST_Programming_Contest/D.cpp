#include <bits/stdc++.h>

using namespace std;

int tc;
int dp[15][15][15][15];

int DP(int pos, int i, int j, int k) {
  if (pos > 10) return 0;
  if (dp[pos][i][j][k] != -1) return dp[pos][i][j][k];
  int ret = 0;
  int rem = 10 - pos + 1;
  if (i > 0 && rem - j > 0 && rem - k > 0) ret = max(ret, 1 + DP(pos + 1, i - 1, j, k));
  if (rem - i > 0 && j > 0 && rem - k > 0) ret = max(ret, 1 + DP(pos + 1, i, j - 1, k));
  if (rem - i > 0 && rem - j > 0 && k > 0) ret = max(ret, 1 + DP(pos + 1, i, j, k - 1));
  if (i > 0 && j > 0 && k > 0) ret = max(ret, 1 + DP(pos + 1, i - 1, j - 1, k - 1));
  return (dp[pos][i][j][k] = ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    memset(dp, -1, sizeof(dp));
    vector<int> cnt(4);
    for (int i = 1; i <= 3; i++) {
      string s;
      cin >> s;
      for (auto e : s) {
        if (e == '1') cnt[i]++;
      }
    }
    int k = DP(1, cnt[1], cnt[2], cnt[3]);
    for (int i = 1; i <= 10; i++) cout << (i <= k ? 1 : 0);
    cout << '\n';
  }

  return 0;
}
