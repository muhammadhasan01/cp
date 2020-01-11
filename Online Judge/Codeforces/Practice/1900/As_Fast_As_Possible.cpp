#include <bits/stdc++.h>

using namespace std;

double n, k, l, v1, v2;

bool can(double t) {
  double onbus = (l - (v1 * t)) / (v2 - v1);
  if (onbus <= 0.0) return true;
  double gp = ceil(n / k);
  double gap = onbus * (v2 - v1);
  double chase = gap / (v2 + v1);
  return (chase * (gp - 1) + onbus * gp <= t);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> l >> v1 >> v2 >> k;
  double l1 = 0.0, r1 = 1e9;
  for (int i = 1; i <= 100; i++) {
    double mid = (l1 + r1) / 2.0;
    if (can(mid)) r1 = mid;
    else l1 = mid;
  }
  cout << fixed << setprecision(12) << r1 << '\n';

  return 0;
}
