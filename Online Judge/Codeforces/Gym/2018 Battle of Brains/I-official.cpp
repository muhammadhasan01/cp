#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 6005;

struct frac {
  long long up, down;
  frac () {}
  frac (long long _u, long long _d) {
    long long g = __gcd(_u, _d);
    up = _u / g, down = _d / g;
  }
  frac operator + (const frac &rhs) const {
    long long nup = up * rhs.down + down * rhs.up;
    long long ndown = down * rhs.down;
    return frac(nup, ndown);
  }
};

int t, cs, d, n;
long long c[10][10];

long long power (long long a, long long e) {
  long long ret = 1;
  while (e--) ret *= a;
  return ret;
}

int main() {
  for (int i = 0; i < 10; ++i) {
    c[i][0] = 1;
  }
  for (int i = 1; i < 10; ++i) {
    for (int j = 1; j <= i; ++j) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
  }
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &d, &n);
    frac ans = frac(0, 1);
    for (int k = 0; k <= d; ++k) {
      long long up = c[d][k] * (1LL << k) * power(n - 2LL, d - k);
      long long down = d + d - k + 1LL;
      ans = ans + frac(up, down);
    }
    printf("Case %d: %lld/%lld\n", ++cs, ans.up, ans.down);
  }
  return 0;
}
