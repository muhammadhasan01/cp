#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int L = log2(N) + 3;
int n, k;
vector<pair<int, int>> g[N];
int tin[N], tout[N], tim;
int up[N][L], cnt[N], ans[N];

void dfs1(int u, int p) {
  tin[u] = ++tim;
  up[u][0] = p;
  for (int i = 1; i < L; i++) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  for (auto v : g[u]) {
    if (v.first == p) continue;
    dfs1(v.first, u);
  }
  tout[u] = ++tim;
}

bool isAncestor(int u, int v) {
  return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v) {
  if (isAncestor(u, v)) return u;
  if (isAncestor(v, u)) return v;
  for (int i = L - 1; i >= 0; i--) {
    if (!isAncestor(up[u][i], v)) {
      u = up[u][i];
    }
  }
  return up[u][0];
}

int dfs2(int u, int p) {
  int ret = cnt[u];
  for (auto v : g[u]) {
    if (v.first == p) continue;
    int z = dfs2(v.first, u);
    ans[v.second] = z;
    ret += z;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  dfs1(1, 1);
  cin >> k;
  while (k--) {
    int u, v;
    cin >> u >> v;
    int w = lca(u, v);
    cnt[w] -= 2;
    cnt[u]++, cnt[v]++;
  }
  dfs2(1, 0);
  for (int i = 1; i < n; i++) {
    cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  }

  return 0;
}
