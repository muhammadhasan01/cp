#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n, m;
vector<pair<int, int>> g[N];
short int dp[N][N][30];

bool dfs(int i, int j, int k) {
  if (dp[i][j][k] != -1) return dp[i][j][k];
  for (auto e : g[i]) {
    int to = e.first;
    int w = e.second;
    if (w < k) continue;
    if (dfs(j, to, w)) return dp[i][j][k] = 0;
  }
  return dp[i][j][k] = 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    char x;
    cin >> u >> v >> x;
    g[u].push_back({v, x - 'a'});
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << (dfs(i, j, 0) ? "B" : "A");
    }
    cout << '\n';
  }

  return 0;
}
