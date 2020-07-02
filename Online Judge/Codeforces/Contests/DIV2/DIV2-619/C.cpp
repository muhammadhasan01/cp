#include <bits/stdc++.h>

using namespace std;

int tc;
long long n, m;

long long f(long long x) {
  return x * (x + 1) / 2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    long long ans = f(n);
    long long k = n - m;
    m++;
    long long d1 = k / m;
    long long n1 = k % m;
    long long n2 = m - n1;
    long long res = n2 * f(d1) + n1 * f(d1 + 1);
    cout << ans - res << '\n';
  }

  return 0;
}
