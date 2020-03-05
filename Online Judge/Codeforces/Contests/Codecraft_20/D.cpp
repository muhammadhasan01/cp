#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n;
pair<int, int> p[N][N];
bool vis[N][N];
char ans[N][N];
int ord[N][N];
pair<int, int> zz = {-1, -1};
int cnt = 0;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int par[N * N];

int fpar(int x) {
  return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void dfs(int x, int y) {
  for (int it = 0; it < 4; it++) {
    int _x = x + dx[it];
    int _y = y + dy[it];
    if (vis[_x][_y]) continue;
    if (_x > n || _x < 1) continue;
    if (_y > n || _y < 1) continue;
    if (p[x][y] != p[_x][_y]) continue;
    vis[_x][_y] = 1;
    int u = fpar(ord[x][y]);
    int v = fpar(ord[_x][_y]);
    par[v] = u;
    if (x < _x) {
      ans[_x][_y] = 'U';
    } else if (x > _x) {
      ans[_x][_y] = 'D';
    } else if (y < _y) {
      ans[_x][_y] = 'L';
    } else if (y > _y) {
      ans[_x][_y] = 'R';
    }
    dfs(_x, _y);
  }
}

void dismiss() {
  cout << "INVALID" << '\n';
  exit(0);
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  bool flag = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x, y;
      cin >> x >> y;
      p[i][j] = {x, y};
      ord[i][j] = ++cnt;
      par[ord[i][j]] = cnt;
      if (x == -1 && y == -1) {
        ans[i][j] = '#';
        continue;
      }
      flag = false;
      ans[x][y] = 'X';
      vis[x][y] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (p[i][j] == zz) {
        bool flag = true;
        for (int it = 0; it < 4; it++) {
          int _i = i + dx[it];
          int _j = j + dy[it];
          if (p[_i][_j] == zz) {
            if (i < _i) {
              ans[i][j] = 'D';
              ans[_i][_j] = 'U';
            } else if (i > _i) {
              ans[i][j] = 'U';
              ans[_i][_j] = 'D';
            } else if (j < _j) {
              ans[i][j] = 'R';
              ans[_i][_j] = 'L';
            } else if (j > _j) {
              ans[i][j] = 'L';
              ans[_i][_j] = 'R';
            }
            flag = false;
            break;
          }
        }
        if (flag) dismiss();
        vis[i][j] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (ans[i][j] != 'X') continue;
      dfs(i, j);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (p[i][j] == zz) continue;
      int u = fpar(ord[p[i][j].first][p[i][j].second]);
      int v = fpar(ord[i][j]);
      if (u != v) dismiss();
    }
  }
  cout << "VALID" << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << ans[i][j];
    }
    cout << '\n';
  }

  return 0;
}