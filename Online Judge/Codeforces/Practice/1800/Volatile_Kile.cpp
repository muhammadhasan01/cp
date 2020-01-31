#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

struct point {
  double x, y;
};

struct line {
  double A, B, C;
  line(point a, point b) {
    A = a.y - b.y;
    B = -a.x + b.x;
    C = -(a.y * B + a.x * A);
  }
  double dist(point p) {
    return (A * p.x + B * p.y + C) / sqrt(A * A + B * B);
  }
};

int n;
point p[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  p[n + 1] = p[1];
  p[n + 2] = p[2];
  double ans = 1e18;
  for (int i = 1; i <= n; i++) {
    line res(p[i], p[i + 2]);
    ans = min(ans, res.dist(p[i + 1]) / 2.0);
  }
  cout << fixed << setprecision(12) << ans << '\n';

  return 0;
}
