#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;
const long long INF = 1e17;

int n;
long long k;
char a[N];
int last[N][30];
long long dp[N][N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 0; j < 26; j++) last[i][j] = last[i - 1][j];
    last[i][a[i] - 'a'] = i;
  }
  for (int len = 1; len <= n - 1; len++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 26; j++) {
        if (len == 1) {
          dp[i][len] = 1;
        } else {
          dp[i][len] = min(INF, dp[i][len] + dp[last[i - 1][j]][len - 1]);
        }
      }
    }
  }
  k--;
  if (k == 0) {
    cout << 0 << '\n';
    return 0;
  }
  long long ans = 0;
  for (int len = n - 1; len >= 0; len--) {
    long long cur = 0;
    long long mul = n - len;
    if (len == 0) cur++;
    else {
      for (int j = 0; j < 26; j++) {
        cur += dp[last[n][j]][len];
      }
    }
    if (cur > k) {
      ans += k * mul;
      k = 0;
    } else {
      ans += cur * mul;
      k -= cur;
    }
    if (k == 0) break;
  }
  if (k > 0) ans = -1;
  cout << ans << '\n';

  return 0;
}
