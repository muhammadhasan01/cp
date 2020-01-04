#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;

int n, m;
int dp[N][N];
vector<int> g[N];
int s[3], t[3], l[3];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    queue<int> q;
    q.push(i);
    dp[i][i] = 1;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : g[u]) {
        if (dp[i][v] == 0) {
          dp[i][v] = 1 + dp[i][u];
          q.push(v);
        }
      }
    }
  }
  for (int i = 1; i <= 2; i++) {
    cin >> s[i] >> t[i] >> l[i];
  }
  int ans = m + 1;
  for (int it = 0; it < 2; it++) {
    swap(s[1], t[1]);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        int p1 = dp[s[1]][i] + dp[i][j] + dp[j][t[1]] - 3;
        int p2 = dp[s[2]][i] + dp[i][j] + dp[j][t[2]] - 3;
        if (p1 <= l[1] && p2 <= l[2]) {
          ans = min(ans, p1 + p2 - dp[i][j] + 1);
        }
      }
    }
  }
  if (dp[s[1]][t[1]] - 1 <= l[1] && dp[s[2]][t[2]] - 1 <= l[2]) {
    ans = min(ans, dp[s[1]][t[1]] + dp[s[2]][t[2]] - 2);
  }
  cout << (ans > m ? -1 : m - ans) << '\n';

  return 0;
}
