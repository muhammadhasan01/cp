#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long M = 998244353;

int n, m;
long long fact[N];
long long inv[N];
long long pre[N];

long long fast(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1) {
      ret = (ret * x) % M;
    }
    y >>= 1;
    x = (x * x) % M;
  }
  return (ret % M + M) % M;
}

long long C(long long a, long long b) {
  if (a < b) return 0;
  if (b == 0) return 1;
  long long ret = fact[a] * inv[b];
  ret %= M;
  ret = (ret * inv[a - b]) % M;
  return (ret % M + M) % M;
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  if (n == 2) {
    cout << 0 << '\n';
    return 0;
  }
  fact[0] = inv[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = (i * fact[i - 1]) % M;
    inv[i] = fast(fact[i], M - 2);
  }
  int strt = n - 1 - (n % 2 == 0);
  for (int i = strt; i <= m; i++) {
    pre[i] += pre[i - 1] + (C(i - 1, n - 2) * (1LL) * (n - 2)) % M;
    pre[i] %= M;
  }
  long long ans = 0;
  for (int i = 2; i <= n - 1; i++) {
    int pos = max(i - 1, n - i);
    long long cur = ((pre[m] - pre[pos]) % M + M) % M;
    ans += (cur * C(n - 3, i - 2));
    ans %= M;
  }
  cout << ans << '\n';

  return 0;
}