#include <bits/stdc++.h>

using namespace std;

int tc;
long long a, m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> a >> m;
    long long g = __gcd(a, m);
    m /= g;
    long long c = m;
    long long res = m;
    for (long long i = 2; i * i <= m; i++) {
      if (m % i == 0) {
        res -= (res / i);
        while (m % i == 0) {
          m /= i;
        }
      }
    }
    if (m > 1) res -= (res / m);
    cout << res << '\n';
  }

  return 0;
}
