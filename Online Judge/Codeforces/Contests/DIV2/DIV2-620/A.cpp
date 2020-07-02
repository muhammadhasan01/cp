#include <bits/stdc++.h>

using namespace std;

int tc;
long long x, y, a, b;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> x >> y >> a >> b;
    long long dif = y - x;
    if (dif % (a + b) == 0) {
      long long k = dif / (a + b);
      cout << k << '\n';
    } else {
      cout << -1 << '\n';
    }
  }

  return 0;
}
