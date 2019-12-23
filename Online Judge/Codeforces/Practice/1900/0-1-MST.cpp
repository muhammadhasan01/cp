#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;
int n, m, src = 1;
int par[N], sz[N];
vector<int> v, g[N];

int fpar(int x) {
  return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
  int pu = fpar(u);
  int pv = fpar(v);
  if (pu == pv) return;
  if (sz[pu] < sz[pv]) swap(pu, pv);
  sz[pu] += sz[pv];
  par[pv] = pu;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    par[i] = i, sz[i] = 1;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if ((int) g[i].size() < (int) g[src].size()) src = i;
  }
  for (int i = 1; i <= n; i++) {
    bool flag = true;
    for (auto e : g[i]) {
      if (e == src) {
        flag = false;
        break;
      }
    }
    if (flag) {
      merge(src, i);
    } else {
      v.push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    g[i].push_back(INF);
    sort(g[i].begin(), g[i].end());
  }
  for (auto e : v) {
    for (int i = 1; i <= n; i++) {
      if (*lower_bound(g[e].begin(), g[e].end(), i) != i) merge(i, e);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (fpar(i) == i) ans++;
  }
  cout << ans - 1 << '\n';

  return 0;
}
