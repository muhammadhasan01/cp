#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
const int S = 2e5 + 5;
const int M = 1e9 + 7;

long long fast(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % M;
    y >>= 1;
    x = (x * x) % M;
  }
  return (ret % M + M) % M;
}

int h, w, n;
long long fact[S];
long long inv[S];
pair<int, int> p[N];
long long dp[N];

long long C(long long x, long long y) {
  if (x < y) return 0;
  long long ret = fact[x] * inv[y];
  ret %= M;
  ret = (ret * inv[x - y]) % M;
  return (ret % M + M) % M;
}

long long decrease(long long x, long long y) {
  return ((x - y) % M + M) % M;
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  fact[0] = 1;
  inv[0] = 1;
  for (long long i = 1; i < S; i++) {
    fact[i] = (i * fact[i - 1]) % M;
    inv[i] = fast(fact[i], M - 2);
  }
  cin >> h >> w >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  p[++n] = {h, w};
  sort(p + 1, p + 1 + n);
  for (int i = 1; i <= n; i++) {
    dp[i] = C(p[i].first + p[i].second - 2, p[i].first - 1);
    for (int j = i - 1; j >= 1; j--) {
      if (p[j].first <= p[i].first && p[j].second <= p[i].second) {
        long long x = p[i].first - p[j].first;
        long long y = p[i].second - p[j].second;
        long long cur = (dp[j] * C(x + y, x)) % M;
        dp[i] = decrease(dp[i], cur);
      }
    }
  }
  cout << dp[n] << '\n';

  return 0;
}