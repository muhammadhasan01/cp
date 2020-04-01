#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int M = 4e3 + 5;

int n, m;
int a[N];
int len = 0;
pair<int, int> occ[M];
bool let[N][N];
int match[M];
int vis[M];
vector<vector<int>> g;

int dfs(int u) {
  vis[u] = 1;
  for (auto v : g[u]) {
    if (!vis[v] && match[v] == v) {
      match[u] = v;
      match[v] = u;
      return 1;
    }
    if (!vis[v] && !vis[match[v]] && match[v] != u) {
      if (dfs(match[v])) {
        match[u] = v;
        match[v] = u;
        return 1;
      }
    }
  }
  return 0;
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i < M; i++) {
    match[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 2; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        while (a[i] % j == 0) {
          occ[++len] = {i, j};
          a[i] /= j;
        }
      }
    }
    if (a[i] > 1) occ[++len] = {i, a[i]};
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    let[u][v] = 1;
    let[v][u] = 1;
  }
  g.resize(len + 1);
  for (int i = 1; i <= len; i++) {
    for (int j = 1; j <= len; j++) {
      if (occ[i].second == occ[j].second && let[occ[i].first][occ[j].first] == 1) {
        g[i].push_back(j);
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= len; i++) {
    memset(vis, 0, sizeof(vis));
    if (match[i] == i) {
      res += dfs(i);
    }
  }
  cout << res << '\n';
  
  return 0;
}