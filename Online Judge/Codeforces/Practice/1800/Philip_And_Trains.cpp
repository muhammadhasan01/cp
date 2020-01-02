#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 5;
const char CC = '/';
int tc;
int n, k;
char s[4][N];


int isValid(int x, int y) {
  return (x > 0 && x < 4 && y < N && (s[x][y] < 'A' || s[x][y] > 'Z'));
}

void dfs(int x, int y) {
  if (y >= N || s[x][y] == CC) return;
  s[x][y] = CC;
  if (isValid(x, y + 1) && isValid(x, y + 2) && isValid(x, y + 3))
    dfs(x, y + 3);
  if (isValid(x, y + 1) && isValid(x - 1, y + 1) && isValid(x - 1, y + 2) && isValid(x - 1, y + 3))
    dfs(x - 1, y + 3);
  if (isValid(x, y + 1) && isValid(x + 1, y + 1) && isValid(x + 1, y + 2) && isValid(x + 1, y + 3))
    dfs(x + 1, y + 3);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> k;
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= 3; i++) {
      cin >> (s[i] + 1);
    }
    for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= n; j++) {
        if (s[i][j] == 's') dfs(i, j);
      }
    }
    bool flag = false;
    for (int i = 1; i <= 3; i++) {
      for (int j = n; j <= n + 3; j++) {
        if (s[i][j] == CC) flag = true;
      }
    }
    cout << (flag ? "YES" : "NO") << '\n';
  }

  return 0;
}
