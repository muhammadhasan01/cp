#include <bits/stdc++.h>

using namespace std;

const int N = 7e3 + 5;

int n;
int k[2];
int a[2][N];
int ans[2][N];
int deg[2][N];
bool vis[2][N];

void dfs(int who, int u) {
  vis[who][u] = 1;
  int ohw = 1 - who;
  for (int i = 0; i < k[ohw]; i++) {
    int v = (n + u - a[ohw][i]) % n;
    if (v == 0 || vis[ohw][v]) continue;
    if (ans[who][u] == 1) {
      ans[ohw][v] = 2;
    } else if (++deg[ohw][v] == k[ohw]) {
      ans[ohw][v] = 1;
    } else {
      continue;
    }
    dfs(ohw, v);
  }
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < 2; i++) {
    cin >> k[i];
    for (int j = 0; j < k[i]; j++) {
      cin >> a[i][j];
    }
  }
  ans[0][0] = ans[1][0] = 1;
  dfs(0, 0);
  dfs(1, 0);
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j < n; j++) {
      if (ans[i][j] == 1) {
        cout << "Lose";
      } else if (ans[i][j] == 2) {
        cout << "Win"; 
      } else {
        cout << "Loop";
      }
      cout << (j == n - 1 ? '\n' : ' ');
    }
  }

  return 0;
}