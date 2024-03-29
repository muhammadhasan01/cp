#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

int n;
int c[N];
vector<int> g[N];
vector<int> order[N];
int ans[N], sz[N];
int root;

void dfs(int u, int p) {
  sz[u] = 1;
  for (auto v : g[u]) {
    if (p == v) continue;
    dfs(v, u);
    for (auto w : order[v]) order[u].push_back(w);
    sz[u] += sz[v];
  }
  if (c[u] > sz[u] - 1) {
    cout << "NO" << '\n';
    exit(0);
  }
  order[u].insert(order[u].begin() + c[u], u);
  cout << "Order for " << u << ": ";
  for (auto i : order[u]) cout << i << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int j;
    cin >> j >> c[i];
    if (j == 0) {
      root = i;
      continue;
    }
    g[i].push_back(j);
    g[j].push_back(i);
  }
  dfs(root, root);
  for (int i = 0; i < n; i++) ans[order[root][i]] = i;
  cout << "YES" << '\n';
  for (int i = 1; i <= n; i++) {
    cout << ans[i] + 1 << (i == n ? '\n' : ' ');
  }

  return 0;
}
