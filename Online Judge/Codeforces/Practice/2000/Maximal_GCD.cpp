#include <bits/stdc++.h>

using namespace std;

long long n, k;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  vector<long long> divisor;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      divisor.push_back(i);
      if (i * i != n) divisor.push_back(n / i);
    }
  }
  sort(divisor.rbegin(), divisor.rend());
  for (auto e : divisor) {
    long long cur = n / e;
    if ((k + 1) > (2 * cur) / k) continue;
    for (int i = 1; i <= k - 1; i++) {
      cout << i * e << " ";
      n -= i * e;
    }
    cout << n << '\n';
    return 0;
  }
  cout << -1 << '\n';

  return 0;
}
