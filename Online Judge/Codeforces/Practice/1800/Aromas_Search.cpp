#include <bits/stdc++.h>

using namespace std;

const long long INF = 2e16;

struct point {
  long long x, y;
  point() {
    x = 0;
    y = 0;
  }
  point(long long _x, long long _y) {
    x = min(INF, _x);
    y = min(INF, _y);
  }
  long long dist(point p) {
    return min(INF, min(INF, abs(p.x - x)) + min(INF, abs(p.y - y)));
  }
};

point p0;
point a, b, s;
long long t;
vector<point> pt;
int ans, len;

long long getDist(int i, int j, int k) {
  if (j < 0 || j >= len) return INF;
  if (k < 0 || k >= len) return INF;
  long long d1 = pt[i].dist(pt[j]);
  long long d2 = pt[i].dist(pt[k]);
  return d1 + d2 + min(d1, d2);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> p0.x >> p0.y >> a.x >> a.y >> b.x >> b.y;
  cin >> s.x >> s.y >> t;
  pt.push_back(p0);
  while (true) {
    point before = pt.back();
    point now = point(min(INF, before.x * a.x) + b.x, min(INF, before.y * a.y) + b.y);
    if (now.x >= INF || now.y >= INF) break;
    pt.push_back(now);
  }
  len = pt.size();
  for (int i = 0; i < len; i++) {
    long long cur_dist = s.dist(pt[i]);
    if (cur_dist > t) continue;
    long long cur_time = t - cur_dist;
    ans = max(ans, 1);
    if (cur_time == 0) continue;
    for (int j = 1; j <= len; j++) {
      for (int k = i; k >= max(0, i - j); k--) {
        long long dist = getDist(i, k, k + j);
        if (dist > cur_time) continue;
        ans = max(ans, j + 1);
        break;
      }
    }
  }
  cout << ans << '\n';

  return 0;
}
