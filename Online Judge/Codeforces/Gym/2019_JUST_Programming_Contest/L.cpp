#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n, m, h, w;
int a[N][N];
int mul, z, ans;
int smaller[N][N], bigger[N][N];

bool can(int x) {
  for (int i = 1; i <= n; i++) {
    int s = 0, b = 0;
    for (int j = 1; j <= m; j++) {
      smaller[i][j] = s + smaller[i - 1][j];
      if (a[i][j] < x)
        smaller[i][j]++, s++;
      bigger[i][j] = b + bigger[i - 1][j];
      if (a[i][j] > x)
        bigger[i][j]++, b++;
    }
  }
  bool ret = false;
  for (int i = 1; i <= n - h + 1; i++) {
    for (int j = 1; j <= m - w + 1; j++) {
      int s = smaller[i + h - 1][j + w - 1] - smaller[i + h - 1][j - 1] - smaller[i - 1][j + w + 1] + smaller[i - 1][j - 1];
      int b = bigger[i + h - 1][j + w - 1] - bigger[i + h - 1][j - 1] - bigger[i - 1][j + w - 1] + bigger[i - 1][j - 1];
      if (s >= b) ret = true;
      if (s == b && s <= mul / 2 && b <= mul / 2) ans = min(ans, x);
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> h >> w;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  mul = n * m;
  int l = 1, r = mul;
  ans = mul;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (can(mid)) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';

  return 0;
}
