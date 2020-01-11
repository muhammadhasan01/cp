#include <bits/stdc++.h>

using namespace std;

const long double eps = 1e-10;

int n;
long long x, y;
long long k;

bool can(long double t) {
  long long hit = floor(t * x) + floor(t * y);
  return (hit >= k);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> x >> y;
  while (n--) {
    cin >> k;
    long double l = 0.0, r = 1e9;
    for (int it = 1; it <= 100; it++) {
      long double mid = (l + r) / 2.0;
      if (can(mid)) r = mid;
      else l = mid;
    }
    long double k1 = r * x;
    long double k2 = r * y;
    bool f1 = (k1 - floor(k1) < eps || ceil(k1) - k1 < eps);
    bool f2 = (k2 - floor(k2) < eps || ceil(k2) - k2 < eps);
    cout << (f1 & f2 ? "Both" : (f1 ? "Vanya" : "Vova")) << '\n';
  }

  return 0;
}
