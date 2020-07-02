#include <bits/stdc++.h>

using namespace std;

struct point {
  long long x, y;
  bool operator==(const point& p) {
    return (x == p.x && y == p.y);
  }
};

const int N = 1e5 + 5;

int n;
point p[N], dif[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  if (n & 1) {
    cout << "NO" << '\n';
    return 0;
  }
  p[n + 1] = p[1];
  for (int i = 1; i <= n; i++) {
    dif[i] = {p[i + 1].x - p[i].x, p[i + 1].y - p[i].y};
  }
  bool flag = true;
  for (int i = 1; i <= n / 2; i++) {
    if (dif[i].x == -dif[i + n / 2].x && dif[i].y == -dif[i + n / 2].y) {
      continue;
    }
    flag = false;
    break;
  }
  cout << (flag ? "YES" : "NO") << '\n';

  return 0;
}
