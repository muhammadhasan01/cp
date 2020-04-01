#include <bits/stdc++.h>

using namespace std;

const int H = 15;
const int W = 1e3 + 5;
const int INF = 2e9;

int h, w, k;
char a[H][W];
int sz[H][W];
int ans;
pair<int, int> v[H];

int sizes(int x1, int y1, int x2, int y2) {
  return sz[x2][y2] - sz[x1 - 1][y2] - sz[x2][y1 - 1] + sz[x1 - 1][y1 - 1];
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> h >> w >> k;
  for (int i = 1; i <= h; i++) {
    int pre = 0;
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
      pre += (a[i][j] == '1');
      sz[i][j] = pre + sz[i - 1][j];
    }
  }
  ans = INF;
  for (int mask = 0; mask < (1 << (h - 1)); mask++) {
    int res = 0;
    int lenz = 0;
    int cur = 1;
    for (int i = 1; i <= h - 1; i++) {
      bool onz = (mask & (1 << (i - 1)));
      if (onz) {
        res++;
        v[++lenz] = {cur, i};
        cur = i + 1;
      }
    }
    v[++lenz] = {cur, h};
    int startz = 1;
    bool flag = true;
    for (int j = 1; j <= w; j++) {
      bool change = false;
      for (int i = 1; i <= lenz; i++) {
        int cursize = sizes(v[i].first, startz, v[i].second, j);
        if (cursize > k) {
          startz = j;
          res++;
          change = true;
          break;
        }
      }
      if (!change) continue;
      for (int i = 1; i <= lenz; i++) {
        int cursize = sizes(v[i].first, startz, v[i].second, j);
        if (cursize > k) {
          flag = false;
          break;
        }
      }
      if (!flag) break;
    }
    if (flag) ans = min(ans, res);
  }
  cout << ans << '\n';

  return 0;
} 