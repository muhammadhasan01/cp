#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;
char a[N][N];
int deg[N][N];

void dismiss() {
  cout << "Not unique" << '\n';
  exit(0);
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] != '.') continue;
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        deg[x][y]++;
      }
    }
  }
  queue<pair<int, int>> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] != '.') continue;
      if (deg[i][j] == 1) q.push({i, j});
    }
  }
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    int i = cur.first;
    int j = cur.second;
    if (a[i][j] != '.') continue;
    int x = -1, y = -1;
    for (int k = 0; k < 4; k++) {
      int _i = i + dx[k];
      int _j = j + dy[k];
      if (a[_i][_j] == '.') {
        x = _i, y = _j;
      }
    }
    if (x == -1 && y == -1) dismiss();
    deg[x][y]--;
    if (i > x) {
      a[x][j] = '^';
      a[i][j] = 'v';
    } else if (i < x) {
      a[i][j] = '^';
      a[x][j] = 'v';
    } else if (j > y) {
      a[i][y] = '<'; a[i][j] = '>';
    } else if (j < y) {
      a[i][j] = '<'; a[i][y] = '>';
    }
    for (int k = 0; k < 4; k++) {
      int _x = x + dx[k];
      int _y = y + dy[k];
      if (a[_x][_y] != '.') continue;
      if (--deg[_x][_y] == 1) {
        q.push({_x, _y});
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '.') dismiss();
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << a[i][j];
    }
    cout << '\n';
  }

  return 0;
}