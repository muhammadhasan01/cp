#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
vector<int> g[N];
long long a[N];
long long dp[N];
long long sz[N];
long long ans;

void dfs(int u, int p, long long h) {
  sz[u] = a[u];
  dp[u] = h * a[u];
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u, h + 1);
    sz[u] += sz[v];
    dp[u] += dp[v];
  }
}

void DP(int u, int p) {
  ans = max(ans, dp[u]);
  for (auto v : g[u]) {
    if (v == p) continue;
    dp[u] += (sz[1] - sz[v] - dp[v]);
    dp[v] += (dp[u] - sz[v]);
    DP(v, u);
    dp[v] -= (dp[u] - sz[v]);
    dp[u] -= (sz[1] - sz[v] - dp[v]);
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
  dfs(1, 1, 0);
  DP(1, 1);
  cout << ans << '\n';

  return 0;
}