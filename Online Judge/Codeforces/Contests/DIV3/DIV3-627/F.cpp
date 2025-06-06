#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
bool a[N];
vector<int> g[N];
int dp[N], ans[N];

void dfs(int u, int p) {
  dp[u] = (a[u] ? 1 : -1);
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    dp[u] += max(0, dp[v]);
  }
}

void DP(int u, int p) {
  ans[u] = dp[u];
  for (auto v : g[u]) {
    if (v == p) continue;
    dp[u] -= max(0, dp[v]);
    dp[v] += max(0, dp[u]);
    DP(v, u);
    dp[v] -= max(0, dp[u]);
    dp[u] += max(0, dp[v]);
  }
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 1);
  DP(1, 1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}