#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, k;
bool vis[N];
vector<int> g[N];
int sz[N];

void dfs(int u, int p) {
  if (vis[u]) sz[u]++;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  k = 2 * k;
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    vis[x] = 1;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 1);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (1LL) * min(sz[i], k - sz[i]);
  }
  cout << ans << '\n';

  return 0;
}
