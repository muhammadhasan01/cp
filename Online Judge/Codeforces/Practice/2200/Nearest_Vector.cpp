#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long double pi = acos(-1);

struct point {
  int pos;
  long double x, y;
  long double angle;
  bool operator<(const point& other) {
    return angle < other.angle;
  }
};

int n;
point a[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
    a[i].pos = i;
    a[i].angle = atan2(a[i].y, a[i].x);
  }
  sort(a + 1, a + 1 + n);
  long double minz;
  int pos_x, pos_y;
  if (a[1].angle < 0 && a[n].angle > 0) {
    minz = pi * 2 - a[n].angle + a[1].angle;
    pos_x = a[1].pos;
    pos_y = a[n].pos;
  } else {
    minz = 10.0;
  }
  for (int i = 1; i < n; i++) {
    a[i].angle = a[i + 1].angle - a[i].angle;
    if (minz > a[i].angle) {
      minz = a[i].angle;
      pos_x = a[i].pos;
      pos_y = a[i + 1].pos;
    }
  }
  cout << pos_x << " " << pos_y << '\n';

  return 0;
}