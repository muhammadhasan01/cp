#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct point {
  int x, y, val;
  point(int _x, int _y, int _v) : x(_x), y(_y), val(_v) {}
  point() : x(0), y(0), val(0) {}
  bool operator<(const point& p) {
    if (x == p.x) return y < p.y;
    return x < p.x;
  }
  bool operator==(const point &p) {
    return (x == p.x && y == p.y);
  }
  point rotate(const point& p, int a, int b) {
    return point(-p.y + a + b, p.x - a + b, p.val + 1);
  }
  friend long long dist(const point& a, const point& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx * dx + dy * dy;
  }
};

int ask(vector<point> &v) {
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++) {
      if (v[i] == v[j]) return INF;
    }
  }
  bool flag = false;
  vector<int> ind(4);
  iota(ind.begin(), ind.end(), 0);
  do {
    point a = v[ind[0]], b = v[ind[1]], c = v[ind[2]], d = v[ind[3]];
    long long d1 = dist(a, b);
    long long d2 = dist(b, c);
    long long d3 = dist(c, d);
    long long d4 = dist(d, a);
    long long d5 = dist(a, c);
    long long d6 = dist(b, d);
    if (d1 != d2) continue;
    if (d1 != d3) continue;
    if (d1 != d4) continue;
    if (d5 != d6) continue;
    flag = true;
    break;
  } while (next_permutation(ind.begin(), ind.end()));
  if (!flag) return INF;
  int ret = 0;
  for (auto e : v) ret += e.val;
  return ret;
}

int n, ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    vector<vector<point>> v;
    v.resize(4);
    ans = INF;
    for (int j = 1; j <= 4; j++) {
      int x, y, a, b;
      cin >> x >> y >> a >> b;
      point p = point(x, y, 0);
      for (int k = 1; k <= 4; k++) {
        v[j - 1].push_back(p);
        p = p.rotate(p, a, b);
      }
    }
    for (int i1 = 0; i1 < 4; i1++) {
      for (int i2 = 0; i2 < 4; i2++) {
        for (int i3 = 0; i3 < 4; i3++) {
          for (int i4 = 0; i4 < 4; i4++) {
            vector<point> tmp;
            tmp.push_back(v[0][i1]);
            tmp.push_back(v[1][i2]);
            tmp.push_back(v[2][i3]);
            tmp.push_back(v[3][i4]);
            int g = ask(tmp);
            ans = min(ans, g);
          }
        }
      }
    }
    if (ans == INF) ans = -1;
    cout << ans << '\n';
  }

  return 0;
}
