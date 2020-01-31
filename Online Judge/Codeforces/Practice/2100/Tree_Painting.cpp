#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
vector<int> g[N];
int sz[N];
int depth[N];
long long dp[N];
long long ans = 0;

void dfs(int u, int p, int h) {
  sz[u]++;
  depth[h]++;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u, h + 1);
    sz[u] += sz[v];
  }
}

void DP(int u, int p) {
  for (auto v : g[u]) {
    if (v == p) continue;
    dp[v] = dp[u] + (1LL) * (n - 2 * sz[v]);
    DP(v, u);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 1, 1);
  for (int i = 1; i <= n; i++) {
    dp[1] += (1LL) * i * depth[i];
  }
  DP(1, 1);
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';

  return 0;
}
