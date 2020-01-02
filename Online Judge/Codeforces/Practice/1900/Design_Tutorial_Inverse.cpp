#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
int n;
long long d[N][N];
vector<pair<int, long long>> g[N];
int par[N], sz[N];
int root;

struct E {
  int u, v;
  long long w;
};

E edges[N * N];
int ledge;

bool cmpr(E a, E b) {
  return (a.w < b.w);
}

int fpar(int x) {
  return (par[x] == x ? x : par[x] = fpar(par[x]));
}

bool merge(int u, int v) {
  int pu = fpar(u);
  int pv = fpar(v);
  if (pu == pv) return false;
  if (sz[pu] < sz[pv]) swap(pu, pv);
  sz[pu] += sz[pv];
  par[pv] = pu;
  return true;
}

void dfs(int u, int p, long long dist) {
  d[root][u] -= dist;
  for (auto e : g[u]) {
    int v = e.first;
    long long w = e.second;
    if (v == p) continue;
    dfs(v, u, dist + w);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> d[i][j];
    }
  }
  bool flag = false;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if ((i == j && d[i][j]) || (d[i][j] != d[j][i])) {
        flag = true;
        break;
      }
      if (i < j) edges[++ledge] = {i, j, d[i][j]};
    }
  }
  if (flag) {
    puts("NO");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    par[i] = i, sz[i] = 1;
  }
  sort(edges + 1, edges + 1 + ledge, cmpr);
  int cnt = 0;
  for (int i = 1; i <= ledge; i++) {
    int xu = edges[i].u;
    int xv = edges[i].v;
    long long xw = edges[i].w;
    if (xw == 0) continue;
    if (merge(xu, xv)) {
      g[xu].push_back({xv, xw});
      g[xv].push_back({xu, xw});
      cnt++;
      if (cnt == n - 1) break;
    }
  }
  if (cnt != n - 1) {
    puts("NO");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    root = i;
    dfs(root, root, 0);
    for (int j = 1; j <= n; j++) {
      if (d[i][j] != 0) {
        flag = true;
        break;
      }
    }
    if (flag) break;
  }
  puts(flag ? "NO" : "YES");

  return 0;
}
