#include <bits/stdc++.h>

using namespace std;

int tc;
long long n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n;
    bool flag = false;
    for (long long i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        long long m = n / i;
        for (long long j = i + 1; j * j <= m; j++) {
          if (m % j == 0) {
            if (m / j == i || j * j == m) continue;
            flag = true;
            cout << "YES" << '\n';
            cout << i << " " << j << " " << m / j << '\n';
            break;
          }
        }
        break;
      }
    }
    if (flag) continue;
    cout << "NO" << '\n';
  }

  return 0;
}
