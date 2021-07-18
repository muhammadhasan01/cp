#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const long double PI = acos(-1);

int t, cs; double m, d;

int main() {
  cin >> t;
  while (t--) {
    cin >> m >> d;
    long double v = m / d;
    long double r = pow(0.75 * v / PI, 1.0 / 3.0);
    long double ans = 4 * PI * r * r;
    printf("Case %d: %0.4f\n", ++cs, (double) ans);
  }
  return 0;
}
