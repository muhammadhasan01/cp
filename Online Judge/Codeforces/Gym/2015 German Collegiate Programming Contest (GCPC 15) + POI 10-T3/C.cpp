#include<bits/stdc++.h>

#define first fi
#define second se

using namespace std;
using ll = long long;
using ld = long double;

const ld EPS = 1e-14, PI = acos(-1);
inline bool lt(ld a, ld b) { return a + EPS < b; }
inline bool le(ld a, ld b) { return a < b + EPS; }

struct point {
  ld x, y;
  point(ld x = 0, ld y = 0) : x(x), y(y) {}
  point operator+(const point& p) const { return point(x+p.x, y+p.y); }
  point operator-(const point& p) const { return point(x-p.x, y-p.y); }
  point operator*(ld s) { return point(x*s, y*s); }
  point operator/(ld s) { return point(x/s, y/s); }
  ld operator%(const point& p) const { return x*p.y - y*p.x; } 
};

ld signedAreaTriangle(point a, point b, point c) {
  return ((a-b) % (c-b)) * 0.5;
}

ld polygonArea(const vector<point>& pt) {
  ld ret = 0.0;
  int sz = (int)pt.size();
  for(int i = 0; i < sz; i++) {
    int next = (i + 1) % sz;
    ret += signedAreaTriangle(pt[i], pt[next], point());
  }
  return abs(ret);
}

vector<point> pts;
ld a, area, threshold;
int n;

ld cut(ld x) {
  ld dec = 0.0;
  for(int i = 0; i < n; i++) {
    int ne = (i + 1) % n;
    int pr = (i + n - 1) % n;
    point a = pts[i];
    point b = a + ((pts[ne] - a) / x);
    point c = a + ((pts[pr] - a) / x);
    dec += abs(signedAreaTriangle(a, b, c));
  }
  return area - dec;
}

void solve() {
  cout << fixed << setprecision(12);
  cin >> a >> n;
  for(int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    pts.emplace_back((ld)x, (ld)y);
  }
  area = polygonArea(pts);
  threshold = a * area;
  ld l = 2., r = 1000.;
  for(int t = 0; t <= 1000; t++) {
    ld mid = (l + r) / 2.0;
    ld curArea = cut(mid);
    if (curArea <= threshold) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}