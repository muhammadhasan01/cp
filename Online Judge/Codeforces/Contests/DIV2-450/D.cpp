#include <bits/stdc++.h>

using namespace std;

const long long M = 1e9 + 7;

long long x, y;

long long mul(int x) {
  long long px = x;
  long long ret = 1;
  for (long long i = 2; i * i <= px; i++) {
    if (x % i == 0) {
      if (x % (i * i) == 0) return 0;
      x /= i;
      ret = -ret;
    }
  }
  if (x != 1) ret = -ret;
  return ret;
}

long long fast(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % M;
    y >>= 1;
    x = (x * x) % M;
  }
  return (ret % M + M) % M;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> x >> y;
  if (y % x) {
    cout << 0 << '\n';
    return 0;
  }
  y /= x;
  long long ans = 0;
  for (long long i = 1; i * i <= y; i++) {
    if (y % i == 0) {
      ans = (ans + mul(y / i) * fast(2, i - 1)) % M;
      if (i * i == y) continue;
      ans = (ans + mul(i) * fast(2, y / i - 1)) % M;
    }
  }
  cout << (ans % M + M) % M << '\n';

  return 0;
}
