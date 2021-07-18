#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

int main() {
  int t, n, a, b, c, d;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b >> c >> d;
    cout << (2 * (a + b + c + d) >= n + 1 ? "Yes" : "No") << '\n';
  }
  return 0;
}
