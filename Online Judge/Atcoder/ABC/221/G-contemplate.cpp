#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 10;
const int D = 1800;
const int maxD = D * 2 + 10;
int n, a, b, x, y;
int d[maxn], g[maxn][maxD], path[maxn][maxD];
bool A[maxn], B[maxn];
void no() {
  puts("No");
  exit(0);
}
void solve(int x, bool* A) {
  for (int i = 1; i <= n; ++i) x += d[i];
  if (x & 1) no();
  x /= 2;
  if (x < 0) no();
  int b = 0, w = 0;  // b: break item    w: totweight
  for (b = 1; b <= n; ++b) {
    w += d[b];
    if (w > x) {
      w -= d[b];
      break;
    }
  }
  fill(g[b - 1], g[b - 1] + maxD, b);
  memset(path, 0, sizeof path);
  if (D + w - x < 0) no();
  g[b - 1][D + w - x] = 0;
  for (int i = b; i <= n; ++i) {
    for (int j = 1; j <= D + D; ++j) g[i][j] = g[i - 1][j];
    for (int j = 1; j <= D; ++j)
      if (g[i - 1][j] < g[i - 1][j + d[i]]) {
        g[i][j + d[i]] = g[i - 1][j];
        path[i][j + d[i]] = i;
      }
    for (int j = D + D; j > D; --j)
      for (int k = g[i][j] + 1; k <= g[i - 1][j]; ++k) {
        if (k < g[i][j - d[k]]) {
          g[i][j - d[k]] = k;
          path[i][j - d[k]] = k;
        }
      }
  }
  if (g[n][D] == b) no();
  int tot = D;
  for (int i = 1; i <= n; ++i) A[i] = i < b ? 1 : 0;
  for (int i = n; i >= b; --i) {
    while (path[i][tot]) {
      int cur = path[i][tot];
      A[cur] ^= 1;
      if (cur < b)
        tot += d[cur];
      else {
        tot -= d[cur];
        break;
      }
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 1; i <= n; ++i) scanf("%d", &d[i]);
  x += a, y += a;
  x -= b, y += b;
  solve(x, A);
  solve(y, B);
  puts("Yes");
  for (int i = 1; i <= n; ++i) {
    if (A[i] && B[i])
      putchar('R');
    else if (A[i])
      putchar('D');
    else if (B[i])
      putchar('U');
    else
      putchar('L');
  }
  return 0;
}