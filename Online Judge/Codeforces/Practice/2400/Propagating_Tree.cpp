#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int M = 2 * N;
int n, m;
int a[N];
vector<int> g[N];
int depth[N];
int t[2][4 * M], lazy[2][4 * M];
int eul[2][M], tin[N], tout[N], tim;

void build(int p, int v, int s, int e) {
  if (s == e) {
    t[p][v] = a[eul[p][s]];
  } else {
    int mid = (s + e) >> 1;
    build(p, v << 1, s, mid);
    build(p, v << 1 | 1, mid + 1, e);
    t[p][v] = t[p][v << 1] + t[p][v << 1 | 1];
  }
}

void update(int p, int v, int s, int e, int l, int r, int val) {
  if (lazy[p][v] != 0) {
    t[p][v] += lazy[p][v];
    if (s != e) {
      lazy[p][v << 1] += lazy[p][v];
      lazy[p][v << 1 | 1] += lazy[p][v];
    }
    lazy[p][v] = 0;
  }
  if (s > r || e < l) return;
  if (l <= s && e <= r) {
    t[p][v] += val;
    if (s != e) {
      lazy[p][v << 1] += val;
      lazy[p][v << 1 | 1] += val;
    }
    return;
  }
  int mid = (s + e) >> 1;
  update(p, v << 1, s, mid, l, r, val);
  update(p, v << 1 | 1, mid + 1, e, l, r, val);
  t[p][v] = t[p][v << 1] + t[p][v << 1 | 1];
}

int get(int p, int v, int s, int e, int l, int r) {
  if (s > r || e < l) return 0;
  if (lazy[p][v] != 0) {
    t[p][v] += lazy[p][v];
    if (s != e) {
      lazy[p][v << 1] += lazy[p][v];
      lazy[p][v << 1 | 1] += lazy[p][v];
    }
    lazy[p][v] = 0;
  }
  if (l <= s && e <= r)
    return t[p][v];
  int mid = (s + e) >> 1;
  return get(p, v << 1, s, mid, l, r) + get(p, v << 1 | 1, mid + 1, e, l, r);
}

void dfs(int u, int p) {
  tin[u] = ++tim;
  eul[depth[u]][tim] = u;
  for (auto v : g[u]) {
    if (v == p) continue;
    depth[v] = 1 - depth[u];
    dfs(v, u);
  }
  tout[u] = ++tim;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 1);
  build(0, 1, 1, tim);
  build(1, 1, 1, tim);
  while (m--) {
    int t, x, val;
    cin >> t >> x;
    if (t == 1) {
      cin >> val;
      update(depth[x], 1, 1, tim, tin[x], tout[x], val);
      update(1 - depth[x], 1, 1, tim, tin[x], tout[x], -val);
    } else {
      cout << get(depth[x], 1, 1, tim, tin[x], tin[x]) << '\n';
    }
  }

  return 0;
}
