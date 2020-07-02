#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int L = ceil(log2(N)) + 10;

int n, q;
vector<int> g[N];
int up[N][L];
int depth[N];
int tin[N], tout[N], tim = 0;

void dfs(int u, int p) {
  up[u][0] = p;
  for (int i = 1; i < L; i++) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  tin[u] = ++tim;
  for (auto v : g[u]) {
    if (v == p) continue;
    depth[v] = depth[u] + 1;
    dfs(v, u);
  }
  tout[u] = ++tim;
}

bool is_lca(int u, int v) {
  return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v) {
  if (is_lca(u, v)) return u;
  if (is_lca(v, u)) return v;
  for (int i = L - 1; i >= 0; i--) {
    if (!is_lca(up[u][i], v)) {
      u = up[u][i];
    }
  }
  return up[u][0];
}

int dist(int u, int v) {
  return depth[u] + depth[v] - 2 * depth[lca(u, v)];
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
  cin >> q;
  while (q--) {
    int x, y, a, b, k;
    cin >> x >> y >> a >> b >> k;
    int d1 = dist(a, b);
    if (d1 <= k && (k - d1) % 2 == 0) {
      cout << "YES" << '\n';
      continue;
    }
    int d2 = min(dist(a, x) + dist(b, y), dist(a, y) + dist(b, x)) + 1;
    if (d2 <= k && (k - d2) % 2 == 0) {
      cout << "YES" << '\n';
      continue;
    }
    cout << "NO" << '\n';
  }

  return 0;
}
