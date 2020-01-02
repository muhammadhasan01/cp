#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

const int N = 1e5 + 5;
const long double pi = acos(-1);

int n;
long double px, py;
pair<long double, long double> p[N];
long double d[N];

long double dist(long double x_1, long double y_1, long double x_2, long double y_2) {
  return (x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cout << fixed << setprecision(18);
  cin >> n >> px >> py;
  long double maks = -2e18, mins = 2e18;
  for (int i = 1; i <= n; i++) {
    long double x, y;
    cin >> x >> y;
    long double cur = dist(px, py, x, y);
    maks = max(maks, cur);
    mins = min(mins, cur);
    p[i] = {x, y};
    d[i] = cur;
  }
  p[n + 1] = p[1];
  d[n + 1] = d[1];
  for (int i = 1; i <= n; i++) {
    long double x = d[i], y = d[i + 1];
    long double z = dist(p[i].ff, p[i].ss, p[i + 1].ff, p[i + 1].ss);
    if (x >= y + z) continue;
    if (y >= x + z) continue;
    long double ar = fabs((p[i].ff - px) * (p[i + 1].ss - py) - (p[i].ss - py) * (p[i + 1].ff - px));
    mins = min(mins, ar * ar / z);
  }
  cout << pi * (maks - mins) << '\n';

  return 0;
}
