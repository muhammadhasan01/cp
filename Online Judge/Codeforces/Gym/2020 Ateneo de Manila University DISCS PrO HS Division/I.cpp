#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

inline ll C3(ll n) { return (n < 3 ? 0 : n * (n - 1) * (n - 2) / 6); }
inline int sgn(ll n) { return (n > 0 ? 1 : (n < 0 ? -1 : 0)); }

struct Point {
  ll x, y;
  Point(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}
  Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
  ll operator%(const Point& p) const { return x * p.y - y * p.x; }
  bool operator<(const Point& p) const { return (y == p.y) ? x < p.x : y < p.y; }
};

inline int ccw(const Point& a, const Point& b, const Point& c) { return sgn((b - a) % (c - b)); }

void sort_circular(vector<pair<Point, int>>& events) {
  vector<pair<Point, int>> upper, lower;
  for(auto& e : events) {
    if(Point() < e.first) { upper.push_back(e); }
    else { lower.push_back(e); }
  }
  auto cmp = [](pair<Point, int> l, pair<Point, int> r) {
    int dir = sgn(l.first % r.first);
    if(dir == 0) { return l.second < r.second; }
    return dir > 0;
  };
  sort(upper.begin(), upper.end(), cmp);
  sort(lower.begin(), lower.end(), cmp);
  for(int i = 0; i < (int)upper.size(); i++) { events[i] = upper[i]; }
  for(int i = 0; i < (int)lower.size(); i++) { events[i + upper.size()] = lower[i]; } 
}

const int N = 300;

vector<Point> ve;
int c2[N + 1][N + 1];
int c3[N + 1][N + 1][N + 1];

void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    ll x, y;
    cin >> x >> y;
    ve.emplace_back(x, y);
  }
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      for(int k = 0; k < n; k++) {
        if(ccw(ve[i], ve[j], ve[k]) == 1) { c2[i][j]++; }
        else if(ccw(ve[i], ve[j], ve[k]) == -1) { c2[j][i]++; }
      }
    }
  }
  for(int i = 0; i < n; i++) {
    vector<pair<Point, int>> temp;
    for(int j = 0; j < n; j++) {
      if(j == i) continue;
      temp.emplace_back(ve[j] - ve[i], j);
    }
    sort_circular(temp);
    vector<int> pos(n);
    for(int j = 0; j < (int)temp.size(); j++) {
      pos[temp[j].second] = j;
    }
    for(int j = 0; j < n; j++) {
      for(int k = j + 1; k < n; k++) {
        if(j == i || k == i) continue;
        int nj = pos[j], nk = pos[k];
        if(nj > nk) swap(nj, nk);
        Point pj = temp[nj].first, pk = temp[nk].first;
        if(ccw(0, pj, pk) == 1) { c3[i][j][k] = c3[i][k][j] = nk - nj - 1; }
        else { c3[i][j][k] = c3[i][k][j] = n - nk + nj - 2; }
      }
    }
  }
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      for(int k = j + 1; k < n; k++) {
        int ni = i, nj = j, nk = k;
        if(ccw(ve[ni], ve[nj], ve[nk]) == -1) swap(nj, nk);
        ll temp = n;
        temp += (c3[ni][nj][nk] + c3[nj][nk][ni] + c3[nk][ni][nj]);
        temp -= (c2[ni][nj] + c2[nj][nk] + c2[nk][ni]);
        ans += C3(1LL * temp);
      }
    }
  }
  cout << ans << '\n';
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