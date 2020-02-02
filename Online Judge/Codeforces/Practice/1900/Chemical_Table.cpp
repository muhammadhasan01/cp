#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<bool>> vis(n + 1, vector<bool>(m + 1));
  vector<int> row(n + 1);
  vector<int> col(m + 1);
  int q;
  cin >> q;
  if (q == 0) {
    cout << n + m - 1 << '\n';
    return 0;
  }
  for (int i = 1; i <= q; i++) {
    int x, y;
    cin >> x >> y;
    vis[x][y] = 1;
    row[x]++;
    col[y]++;
  }
  vector<vector<bool>> pre_row(n + 2, vector<bool>(m + 2));
  vector<vector<bool>> suf_row(n + 2, vector<bool>(m + 2));
  vector<vector<bool>> pre_col(m + 2, vector<bool>(n + 2));
  vector<vector<bool>> suf_col(m + 2, vector<bool>(n + 2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pre_row[i][j] = pre_row[i - 1][j];
      if (row[i] > 1 && vis[i][j]) pre_row[i][j] = true;
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      suf_row[i][j] = suf_row[i + 1][j];
      if (row[i] > 1 && vis[i][j]) suf_row[i][j] = true;
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      pre_col[i][j] = pre_col[i - 1][j];
      if (col[i] > 1 && vis[j][i]) pre_col[i][j] = true;
    }
  }
  for (int i = m; i >= 1; i--) {
    for (int j = 1; j <= n; j++) {
      suf_col[i][j] = suf_col[i + 1][j];
      if (col[i] > 1 && vis[j][i]) suf_col[i][j] = true;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (vis[i][j]) continue;
      if (pre_row[i - 1][j] || suf_row[i + 1][j]) {
        if (pre_col[j - 1][i] || suf_col[j + 1][i]) {
          vis[i][j] = 1;
          row[i]++;
          col[j]++;
        }
      }
    }
  }
  int max_row = 0;
  for (int i = 1; i <= n; i++) {
    max_row = max(max_row, row[i]);
  }
  int max_col = 0;
  for (int i = 1; i <= m; i++) {
    max_col = max(max_col, col[i]);
  }
  int ans = n - max_row + m - max_col;
  for (int i = 1; i <= n; i++) {
    if (row[i] > 1) ans--;
  }
  if (max_row == 1 && max_col == 1) ans++;
  cout << ans << '\n';

  return 0;
}
