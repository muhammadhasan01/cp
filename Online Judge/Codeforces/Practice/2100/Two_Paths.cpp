#include <bits/stdc++.h>

using namespace std;

const int N = 205;

int n;
int ans;
int exc;
int _u, dist;
vector<int> g[N];

void dp(int u, int p, int h) {
  if (h >= dist) {
    dist = h;
    _u = u;
  }
  for (auto v : g[u]) {
    if (v == p) continue;
    if (v == exc) continue;
    dp(v, u, h + 1);
  }
}

int diameter(int x) {
  dist = 0;
  _u = x;
  dp(x, x, 0);
  dist = 0;
  dp(_u, _u, 0);
  return dist;
}

void dfs(int u, int p) {
  for (auto v : g[u]) {
    if (v == p) continue;
    exc = u;
    int res_1 = diameter(v);
    exc = v;
    int res_2 = diameter(u);
    ans = max(ans, res_1 * res_2);
    dfs(v, u);
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
  dfs(1, 1);
  cout << ans << '\n';

  return 0;
}