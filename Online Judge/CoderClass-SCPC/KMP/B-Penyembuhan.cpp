#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 305;
 
struct st {
  int i, j, k;
};
 
string a, b, c;
int p, q, r;
int dp[N][N][N];
st par[N][N][N];
int lps[N];
int go[N][30];
 
int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
  cin >> a >> b >> c;
  p = a.size(), q = b.size(), r = c.size();
  for (int i = 1, j = 0; i < r; i++) {
    while (j > 0 && c[i] != c[j]) j = lps[j - 1];
    j += (c[i] == c[j]);
    lps[i] = j;
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < 26; j++) {
      if (j == (int) (c[i] - 'A')) {
        go[i][j] = i + 1;
      } else {
        go[i][j] = (i > 0 ? go[lps[i - 1]][j] : 0);
      }
    }
  }
  dp[0][0][0] = 0;
  for (int i = 0; i <= p; i++) {
    for (int j = 0; j <= q; j++) {
      for (int k = 0; k < r; k++) {
        if (i + 1 <= p) {
          int was = dp[i + 1][j][k];
          dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
          if (was != dp[i + 1][j][k]) {
            par[i + 1][j][k] = {i, j, k};
          }
        }
        if (j + 1 <= q) {
          int was = dp[i][j + 1][k];
          dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
          if (was != dp[i][j + 1][k]) {
            par[i][j + 1][k] = {i, j, k};
          }
        }
        if (i < p && j < q && a[i] == b[j]) {
          int p = go[k][(int) (a[i] - 'A')];
          if (p < r) {
            int was = dp[i + 1][j + 1][p];
            dp[i + 1][j + 1][p] = max(dp[i + 1][j + 1][p], 1 + dp[i][j][k]);
            if (was != dp[i + 1][j + 1][p]) {
              par[i + 1][j + 1][p] = {i, j, k};
            }
          }
        }
      }
    }
  }
  int x = -1, y = -1, z = -1;
  int ans = 0;
  for (int i = 0; i < r; i++) {
    int was = ans;
    ans = max(ans, dp[p][q][i]);
    if (was != ans) {
      x = p, y = q, z = i;
    }
  }
  if (ans == 0) {
    cout << -1 << '\n';
    return 0;
  }
  string res = "";
  while (dp[x][y][z]) {
    auto cur = par[x][y][z];
    if (cur.i != x && cur.j != y) {
      res += a[x - 1];
    }
    x = cur.i, y = cur.j, z = cur.k;
  }
  reverse(res.begin(), res.end());
  cout << res << '\n';
 
  return 0;
}