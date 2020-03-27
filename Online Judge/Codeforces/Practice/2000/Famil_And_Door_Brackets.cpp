#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int K = 2e3 + 5;
const int INF = 2e9;
const long long M = 1e9 + 7;

int n, m;
string s;
long long dp[K][K];
long long ans;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> s;
  int l = 0, r = 0, mins = INF;
  for (int i = 0; i < m; i++) {
    if (s[i] == '(') {
      l++;
    } else if (s[i] == ')') {
      r++;
    }
    mins = min(mins, l - r);
  }
  dp[0][0] = 1;
  for (int i = 1; i < K; i++) {
    dp[i][0] = dp[i - 1][1];
    for (int j = 1; j <= i; j++) {
      dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % M;
    }
  }
  for (int i = 0; i <= n - m; i++) {
    for (int j = max(0, -mins); j <= i; j++) {
      int k = j + l - r;
      if (k > n - m - i) continue;
      ans = (ans + (dp[i][j] * dp[n - m - i][k]) % M) % M;
    }
  }
  cout << (ans % M + M) % M << '\n';

  return 0;
}