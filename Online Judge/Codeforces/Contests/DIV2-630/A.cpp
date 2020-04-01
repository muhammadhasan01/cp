#include <bits/stdc++.h>

using namespace std;

int tc;
long long a, b, c, d;
long long x, y, x_1, y_1, x2, y2;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> a >> b >> c >> d;
    cin >> x >> y >> x_1 >> y_1 >> x2 >> y2;
    if (x_1 == x2) {
      if (a > 0 || b > 0) {
        cout << "No" << '\n';
        continue;
      }
    }
    if (y_1 == y2) {
      if (c > 0 || d > 0) {
        cout << "No" << '\n';
        continue;
      }
    }
    long long resx = -a + b;
    long long resy = -c + d;
    x += resx;
    y += resy;
    if (x < x_1 || x > x2) {
      cout << "No" << '\n';
    } else if (y < y_1 || y > y2) {
      cout << "No" << '\n';
    } else {
      cout << "Yes" << '\n';
    }
  }

  return 0;
}