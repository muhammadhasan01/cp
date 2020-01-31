#include <bits/stdc++.h>

using namespace std;

const long long INF = 2e9;

long long a, b, x, y;

bool can(long long k) {
  return (k * x <= a && k * y <= b);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> a >> b >> x >> y;
  long long g = __gcd(x, y);
  x /= g;
  y /= g;
  long long l = 1, r = INF, res_x = 0, res_y = 0;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (can(mid)) {
      l = mid + 1;
      res_x = x * mid;
      res_y = y * mid;
    } else {
      r = mid - 1;
    }
  }
  cout << res_x << " " << res_y << '\n';

  return 0;
}
