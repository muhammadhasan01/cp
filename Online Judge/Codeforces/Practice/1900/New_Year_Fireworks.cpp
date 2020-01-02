#include <bits/stdc++.h>

using namespace std;

const int N = 35;
const int M = 315;

int n;
int t[N];
bitset<N> dp[M][M][8];
bitset<M> vis[M];
int ans;

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

void dfs(int x, int y, int dir, int pos) {
  dp[x][y][dir][pos] = 1;
  for (int i = 1; i <= t[pos]; i++) {
    x += dx[dir];
    y += dy[dir];
    if (vis[x][y] == 0) {
      vis[x][y] = 1;
      ans++;
    }
  }
  if (pos == n) return;
  vector<int> curdir(2);
  curdir[0] = ((dir - 1) % 8 + 8) % 8;
  curdir[1] = ((dir + 1) % 8 + 8) % 8;
  for (int i = 0; i < 2; i++) {
    if (dp[x][y][curdir[i]][pos + 1] == 0)
      dfs(x, y, curdir[i], pos + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  dfs(155, 155, 0, 1);
  cout << ans << '\n';

  return 0;
}
