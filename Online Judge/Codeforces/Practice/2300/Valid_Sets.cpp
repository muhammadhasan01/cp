#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
const int M = 1e9 + 7;

int n, d;
vector<int> g[N];
bool vis[N];
int c[N];
int cur;

long long dfs(int u, int p) {
  if (c[u] == c[cur] && u != cur && vis[u]) return 0LL;
  if (c[u] > c[cur] + d || c[u] < c[cur]) return 0LL;
  long long ret = 1;
  for (auto v : g[u]) {
    if (v == p) continue;
    ret = (ret * (1 + dfs(v, u))) % M;
  }
  return ret;
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> d >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    cur = i;
    vis[i] = 1;
    ans = (ans + dfs(i, i)) % M;
  }
  cout << ans << '\n';

  return 0;
}