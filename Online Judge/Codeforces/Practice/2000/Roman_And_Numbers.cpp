#include <bits/stdc++.h>

using namespace std;

const int K = 18;
const int N = (1 << K);
const int M = 105;

string s;
int m;
int a[K];
int cnt[K];
long long dp[N][M];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s >> m;
  reverse(s.begin(), s.end());
  int len = s.size();
  for (int i = 0; i < len; i++) {
    a[i] = (int) (s[i] - '0');
    cnt[a[i]]++;
  }
  dp[0][0] = 1;
  for (int i = 0; i < (1 << len); i++) {
    for (int j = 0; j < m; j++) {
      if (!dp[i][j]) continue;
      if (__builtin_popcount(i) == 1 && a[__builtin_ctz(i)] == 0) continue;
      for (int k = 0; k < len; k++) {
        bool b = (i & (1 << k));
        if (b) continue;
        dp[(i | (1 << k))][(j * 10 + a[k]) % m] += dp[i][j];
      }
    }
  }
  long long res = dp[(1 << len) - 1][0];
  for (int i = 0; i <= 9; i++) {
    for (int j = 1; j <= cnt[i]; j++) {
      res /= j;
    }
  }  
  cout << res << '\n';

  return 0;
}