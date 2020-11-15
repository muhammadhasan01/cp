#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;
long long n, x, y;
long long dp[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> x >> y;
  dp[1] = x;
  for (int i = 2; i <= n; i++) {
    dp[i] = min(x + dp[i - 1], dp[(i + 1) / 2] + y + (i & 1) * x);
  }
  cout << dp[n] << '\n';

  return 0;
}
