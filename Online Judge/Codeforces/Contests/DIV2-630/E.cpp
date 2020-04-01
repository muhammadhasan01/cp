#include <bits/stdc++.h>

using namespace std;

const long long M = 998244353;

long long n, m, L, R;

long long fast(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % M;
    y >>= 1;
    x = (x * x) % M;
  }
  return ret;
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> L >> R;
  long long lenz = (R - L + 1);
  long long area = n * m;
  long long res = fast(lenz, area);
  if (area % 2 == 0) {
    res = (res + (lenz & 1)) % M;
    res = (res * fast(2, M - 2)) % M;
  }
  cout << (res % M + M) % M << '\n';

  return 0;
}