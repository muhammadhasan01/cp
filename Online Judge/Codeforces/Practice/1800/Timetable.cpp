#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int INF = 1e9;

int n, m, k;
vector<int> v[N];
int pd[N][N], dp[N][N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == '1') {
        v[i].push_back(j);
      }
    }
    int len = v[i].size();
    for (int skip = 0; skip <= k; skip++) {
      if (len - skip <= 0) break;
      pd[i][skip] = INF;
      for (int j = 0; j <= skip; j++) {
        pd[i][skip] = min(pd[i][skip], v[i][len - skip + j - 1] - v[i][j] + 1);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      if (i == 1) {
        dp[i][j] = pd[i][j];
      } else {
        dp[i][j] = INF;
        for (int z = 0; z <= j; z++) {
          dp[i][j] = min(dp[i][j], dp[i - 1][z] + pd[i][j - z]);
        }
      }
    }
  }
  cout << dp[n][k] << '\n';

  return 0;
}
