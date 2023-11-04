#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#define int long long

using namespace std;
const int N = 2010;

int n, mn, a[N], d[N][N], e[N][N];

signed main() {
  cin >> n;
  int now = 0, x;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (x) {
      a[++now] = x;
      if (now > 128) break;
    }
  }
  if (now > 128) {
    puts("3");
    return 0;
  }
  for (int i = 1; i <= now; i++) {
    for (int j = 1; j <= now; j++) {
      if (i != j && a[i] & a[j])
        d[i][j] = e[i][j] = 1;
      else
        d[i][j] = e[i][j] = 1e9;
    }
  }
  mn = 1e9;
  for (int k = 1; k <= now; k++) {
    for (int i = 1; i < k; i++) {
      for (int j = i + 1; j < k; j++) {
        mn = min(mn, e[i][k] + e[k][j] + d[i][j]);
      }
    }
    for (int i = 1; i <= now; i++) {
      for (int j = 1; j <= now; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  if (mn < 1e9)
    cout << mn;
  else
    cout << -1 << endl;
}