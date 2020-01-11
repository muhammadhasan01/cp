#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;

string s;
int n, q;
int dp[N][N];
bool ok[N][N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  n = s.length();
  s = "$" + s + "$";
  for (int len = 1; len <= n; len++) {
    for (int i = 1; i <= n; i++) {
      int j = i + len - 1;
      if (j > n) break;
      if (len == 1) {
        dp[i][j] = 1;
        ok[i][j] = 1;
      } else {
        dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
        if (s[i] == s[j]) ok[i][j] = (len == 2 ? 1 : ok[i + 1][j - 1]);
        if (ok[i][j]) dp[i][j]++;
      }
    }
  }

  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << dp[l][r] << '\n';
  }

  return 0;
}
