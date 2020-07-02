#include <bits/stdc++.h>

using namespace std;

int tc;
long long a, b, c, r;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> a >> b >> c >> r;
    if (a > b) swap(a, b);
    long long c1 = c - r, c2 = c + r;
    if (b < c1) {
      cout << b - a << '\n';
    } else if (a <= c1 && c1 <= b) {
      cout << c1 - a + max(0LL, b - c2) << '\n';
    } else if (c1 < a) {
      if (b < c2) {
        cout << 0 << '\n';
      } else if (a <= c2 && c2 <= b) {
        cout << b - c2 << '\n';
      } else {
        cout << b - a << '\n';
      }
    }
  }

  return 0;
}
