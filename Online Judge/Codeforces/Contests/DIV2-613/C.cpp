#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

long long x;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> x;
  long long bf = x;
  vector<long long> primes;
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      long long cur = 1;
      while (x % i == 0) {
        x /= i;
        cur *= i;
      }
      primes.push_back(cur);
    }
  }
  if (x > 1) primes.push_back(x);
  int len = primes.size();
  long long ans = INF;
  long long a, b;
  for (int i = 0; i < (1 << len); i++) {
    long long res = 1;
    for (int j = 0; j < len; j++) {
      bool b = i & (1 << j);
      if (b) {
        res = (res * primes[j]);
      }
    }
    res = max(res, bf / res);
    if (ans > res) {
      ans = res;
      a = bf / res;
      b = res;
    }
  }
  cout << a << " " << b << '\n';

  return 0;
}
