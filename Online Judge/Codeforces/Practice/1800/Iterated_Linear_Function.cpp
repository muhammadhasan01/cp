#include <bits/stdc++.h>

using namespace std;

const long long M = 1e9 + 7;

long long A, B, n, x;
long long ans;

long long fast(long long x, long long y, long long p) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % p;
    y >>= 1;
    x = (x * x) % p;
  }
  return (ret % p + p) % p;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> A >> B >> n >> x;
  if (n == 0) {
    cout << x << '\n';
    return 0;
  }
  A %= M; B %= M; x %= M;
  long long An = fast(A, n, M);
  long long Am;
  if (A == 1) {
    Am = n % M;
  } else {
    Am = (An - 1) * (fast(A - 1, M - 2, M));
    Am = (Am % M + M) % M;
  }
  long long ans = (An * x) + (Am * B);
  cout << (ans % M + M) % M << '\n';

  return 0;
}
