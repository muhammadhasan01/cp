#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;
int n, m;
vector<pair<int, int>> g[N];
short int col[N];
int ans[N];
bool cycle;

void dfs(int u) {
  col[u] = 1;
  for (auto e : g[u]) {
    int v = e.first;
    int idx = e.second;
    if (col[v] == 0) {
      dfs(v);
      ans[idx] = 1;
    } else if (col[v] == 1) {
      ans[idx] = 2;
      cycle = true;
    } else {
      ans[idx] = 1;
    }
  }
  col[u] = 2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back({v, i});
  }
  for (int i = 1; i <= n; i++)
    if (col[i] == 0)
      dfs(i);

  cout << (cycle ? 2 : 1) << '\n';
  for (int i = 1; i <= m; i++)
    cout << ans[i] << (i == m ? '\n' : ' ');

  return 0;
}
