#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int L = log2(N) + 5;

int n, m;
vector<int> g[N];
int ask[N];
int up[N][L];
int tin[N], tout[N], tim = 0;
int depth[N];

void dfs(int u, int p, int h) {
  depth[u] = h;
  up[u][0] = p;
  for (int i = 1; i < L; i++) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  tin[u] = ++tim;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u, h + 1);
  }
  tout[u] = ++tim;
}

bool is_anc(int u, int v) {
  return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v) {
  if (is_anc(u, v)) return u;
  if (is_anc(v, u)) return v;
  for (int i = L - 1; i >= 0; i--) {
    if (!is_anc(up[u][i], v)) {
      u = up[u][i];
    }
  }
  return up[u][0];
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 1, 0);
  while (m--) {
    int k;
    cin >> k;
    int node = 0, dpt = -1;
    for (int i = 1; i <= k; i++) {
      cin >> ask[i];
      if (depth[ask[i]] > dpt) {
        dpt = depth[ask[i]];
        node = ask[i];
      }
    }
    bool flag = true;
    for (int i = 1; i <= k; i++) {
      int LCA = lca(ask[i], node);
      if (depth[ask[i]] - depth[LCA] > 1) {
        flag = false;
        break;
      }
    }
    cout << (flag ? "YES" : "NO") << '\n';
  }

  return 0;
}