#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n;
int c[N], sz[N], child[N];
int tot, maks, childz;
long long ans[N], cnt[N], cur;
vector<int> g[N];

void dfs1(int u, int p) {
  sz[u]++;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs1(v, u);
    sz[u] += sz[v];
    if (sz[v] > sz[child[u]]) child[u] = v;
  }
}

void add(int u, int p, int val) {
  cnt[c[u]] += val;
  if (cnt[c[u]] > maks) {
    maks = cnt[c[u]];
    cur = c[u];
  } else if (cnt[c[u]] == maks) {
    cur += c[u];
  }
  for (auto v : g[u]) {
    if (v == p || v == childz) continue;
    add(v, u, val);
  }
}

void dfs2(int u, int p, bool op) {
  for (auto v : g[u]) {
    if (v == p || v == child[u]) continue;
    dfs2(v, u, 1);
  }
  if (child[u] > 0) dfs2(child[u], u, 0);
  childz = child[u];
  add(u, p, 1);
  ans[u] = cur;
  if (op) {
    childz = 0;
    add(u, p, -1);
    maks = cur = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs1(1, 0);
  dfs2(1, 0, 0);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
