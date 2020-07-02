#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;
const int L = ceil(log2(N)) + 5;
const int INF = 1e6;

struct query {
  int l, r, vl, par;
};

int n, m;
vector<pair<int, int>> g[N];
int up[N][L];
int tin[N], tout[N], tim = 0;
int ord[N];
query q[N];
int val[N], p[N];

void dfs(int u, int p) {
  up[u][0] = p;
  for (int i = 1; i < L; i++) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  tin[u] = ++tim;
  for (auto e : g[u]) {
    int v = e.first;
    int idx = e.second;
    if (v == p) continue;
    ord[v] = idx;
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
  dfs(1, 1);
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    int pr = lca(u, v);
    q[i] = {u, v, w, pr};
    while (u != pr) {
      if (val[ord[u]] < w) val[ord[u]] = w;
      if (u == pr) break;
      u = up[u][0];
    }
    while (v != pr) {
      if (val[ord[v]] < w) val[ord[v]] = w;
      if (v == pr) break;
      v = up[v][0];
    }
  }
  bool flag = false;
  for (int i = 1; i <= m; i++) {
    int u = q[i].l;
    int v = q[i].r;
    int w = q[i].vl;
    int pr = q[i].par;
    int mini = INF + 500;
    while (u != pr) {
      mini = min(mini, val[ord[u]]);
      if (u == pr) break;
      u = up[u][0];
    }
    while (v != pr) {
      mini = min(mini, val[ord[v]]);
      if (v == pr) break;
      v = up[v][0];
    }
    if (mini != w) {
      flag = true;
      break;
    }
  }
  if (flag) {
    cout << -1 << '\n';
  } else {
    for (int i = 1; i < n; i++) {
      if (val[i] == 0) val[i] = INF;
      cout << val[i] << (i == n - 1 ? '\n' : ' ');
    }
  }

  return 0;
}
