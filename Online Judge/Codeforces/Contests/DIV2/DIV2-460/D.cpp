#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
int n, m;
int val[N];
vector<int> g[N], rg[N];
int col[N];
int dp[N][30];

bool dfs(int u) {
  col[u] = 1;
  for (auto v : g[u]) {
    if (col[v] == 0) {
      if (dfs(v)) return true;
    } else if (col[v] == 1) {
      return true;
    }
  }
  col[u] = 2;
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    char x;
    cin >> x;
    val[i] = (x - 'a');
  }
  vector<int> deg(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    rg[v].push_back(u);
    deg[u]++;
  }
  for (int i = 1; i <= n; i++) {
    if (dfs(i)) {
      cout << -1 << '\n';
      return 0;
    }
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) {
      q.push(i);
      dp[i][val[i]]++;
    }
  }
  for (int it = 0; it < 26; it++) {
    queue<int> cq = q;
    vector<int> cdeg = deg;
    while (!cq.empty()) {
      int u = cq.front();
      cq.pop();
      for (auto v : rg[u]) {
        dp[v][it] = max(dp[v][it], dp[u][it] + (val[v] == it));
        if (--cdeg[v] == 0) {
          cq.push(v);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int it = 0; it < 26; it++) {
      ans = max(ans, dp[i][it]);
    }
  }
  cout << ans << '\n';

  return 0;
}
