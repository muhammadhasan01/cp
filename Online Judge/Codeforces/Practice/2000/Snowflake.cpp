#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int n, q;
int dp[N], par[N], sz[N];
int msz[N];
vector<int> g[N];

void dfs(int u) {
  sz[u] = 1;
  for (auto v : g[u]) {
    dfs(v);
    sz[u] += sz[v];
    msz[u] = max(msz[u], sz[v]);
  }
}

void DP(int u) {
  bool flag = true;
  int nodes = sz[u];
  int maks = -1;
  int v = 0;
  for (auto _v : g[u]) {
    DP(_v);
    if (sz[_v] > maks) {
      maks = sz[_v];
      v = dp[_v];
    }
    if (sz[_v] > nodes / 2) {
      flag = false;
    }
  }
  if (flag) {
    dp[u] = u;
    return;
  }
  while (v != u) {
    flag = true;
    if (sz[u] - sz[v] > nodes / 2) flag = false;
    if (msz[v] > nodes / 2) flag = false;
    if (flag) {
      dp[u] = v;
      return;
    }
    v = par[v];
  }
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    int j;
    cin >> j;
    g[j].push_back(i);
    par[i] = j;
  }
  par[1] = 1;
  dfs(1);
  DP(1);
  while (q--) {
    int u;
    cin >> u;
    cout << dp[u] << '\n';
  }

  return 0;
}