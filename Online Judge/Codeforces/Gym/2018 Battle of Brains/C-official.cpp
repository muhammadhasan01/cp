#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const long double PI = acos(-1);

int t, cs; double r;

int main() {
  cin >> t;
  while (t--) {
    cin >> r;
    long double ans = r * r / 4.0;
    printf("Case %d: %0.4f\n", ++cs, (double) ans);
  }
  return 0;
}
