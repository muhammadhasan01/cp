#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
vector<int> g[N];
int a, b, c;
int da, db, ans;
bool vis[N];
int sz[N];
int par[N];

void dfs(int u, int p, int depth) {
  if (da != -1 && depth > da) {
    da = depth;
    a = u;
  } else if (da == -1 && depth > db) {
    db = depth;
    b = u;
  }
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u, depth + 1);
  }
}

void DP(int u, int p) {
  par[u] = p;
  for (auto v : g[u]) {
    if (v == p) continue;
    DP(v, u);
  }
}

pair<int, int> get(int u, int p) {
  int ret = 0;
  int retu = u;
  for (auto v : g[u]) {
    if (vis[v]) continue;
    if (v == p) continue;
    pair<int, int> cur = get(v, u);
    if (cur.first + 1 > ret) {
      ret = cur.first + 1;
      retu = cur.second;
    }
  }
  return {ret, retu};
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
  dfs(1, 1, 0);
  da = -1;
  dfs(a, a, 0);
  DP(a, a);
  c = par[b];
  ans = db;
  for (int x = b; ;x = par[x]) {
    vis[x] = 1;
    vis[par[x]] = 1;
    for (auto y : g[x]) {
      if (vis[y]) continue;
      pair<int, int> temp = get(y, y);
      if (db + temp.first + 1 > ans) {
        ans = db + temp.first + 1;
        c = temp.second;
      }
    }
    if (x == a) break;
  }
  cout << ans << '\n';
  cout << a << " " << b << " " << c << '\n';

  return 0;
}
