#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int M = 2e4 + 5;

int n, m, k;
int a[N][M];
int pre[N][M];
int dp[N][M];

int t[4 * M], lazy[4 * M];
int cur_idx;

void build(int v, int s, int e) {
  if (s == e) {
    t[v] = dp[cur_idx][s];
  } else {
    int mid = (s + e) / 2;
    build(2 * v, s, mid);
    build(2 * v + 1, mid + 1, e);
    t[v] = max(t[2 * v], t[2 * v + 1]);
  }
}

void push(int v) {
  if (lazy[v] == 0) return;
  lazy[2 * v] += lazy[v];
  lazy[2 * v + 1] += lazy[v];
  t[2 * v] += lazy[v];
  t[2 * v + 1] += lazy[v];
  lazy[v] = 0;
}

void updateRange(int v, int s, int e, int l, int r, int val) {
  if (l > r) return;
  if (l == s && e == r) {
    t[v] += val;
    lazy[v] += val;
    return;
  }
  push(v);
  int mid = (s + e) / 2;
  updateRange(2 * v, s, mid, l, min(r, mid), val);
  updateRange(2 * v + 1, mid + 1, e, max(mid + 1, l), r, val);
  t[v] = max(t[2 * v], t[2 * v + 1]);
}

int getz(int v, int s, int e, int l, int r) {
  if (l > r) return 0;
  if (l <= s && e <= r) return t[v];
  push(v);
  int mid = (s + e) / 2;
  return max(getz(2 * v, s, mid, l, min(r, mid)), getz(2 * v + 1, mid + 1, e, max(l, mid + 1), r));
}

int get(int x1, int y1, int x2, int y2) {
  return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n + 1; i++) {
    int cur = 0;
    for (int j = 1; j <= m; j++) {
      cur += a[i][j];
      pre[i][j] = cur + pre[i - 1][j];
    }
  }
  for (int j = 1; j <= m - k + 1; j++) {
    dp[1][j] = get(1, j, 2, j + k - 1);
  }
  for (int i = 2; i <= n; i++) {
    memset(t, 0, sizeof(t));
    memset(lazy, 0, sizeof(lazy));
    cur_idx = i - 1;
    build(1, 1, m);
    for (int j = 1; j <= m - k + 1; j++) {
      if (j == 1) {
        for (int l = 1; l <= k; l++) {
          updateRange(1, 1, m, 1, l, -a[i][l]);
        }
      } else {
        updateRange(1, 1, m, max(1, j - k), j - 1, a[i][j - 1]);
        updateRange(1, 1, m, j, j + k - 1, -a[i][j + k - 1]);
      }
      dp[i][j] = get(i, j, i + 1, j + k - 1) + getz(1, 1, m, 1, m);
    }
  }
  int ans = 0;
  for (int j = 1; j <= n; j++) {
    ans = max(ans, dp[n][j]);
  }
  cout << ans << '\n';

  return 0;
}