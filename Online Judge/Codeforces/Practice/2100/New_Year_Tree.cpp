#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

int n, q;
int tp, vp, cp;
vector<int> g[N];
int eul[2 * N];
int tin[N], tout[N], tim;
long long c[N];
long long t[8 * N];
long long lazy[8 * N];

void dfs(int u, int p) {
  tin[u] = ++tim;
  eul[tim] = u;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
  tout[u] = ++tim;
  eul[tim] = u;
}

void build(int v, int s, int e) {
  if (s == e) {
    t[v] = c[eul[s]];
  } else {
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    t[v] = (t[v << 1] | t[v << 1 | 1]);
  }
}

void push(int v, int s, int e) {
  if (s == e || lazy[v] == 0) return;
  t[v << 1] = lazy[v];
  t[v << 1 | 1] = lazy[v];
  lazy[v << 1] = lazy[v];
  lazy[v << 1 | 1] = lazy[v];
  lazy[v] = 0;
}

void updateRange(int v, int s, int e, int l, int r, long long val) {
  if (l > r)
    return;
  if (l == s && e == r) {
    t[v] = val;
    lazy[v] = val;
    return;
  }
  push(v, s, e);
  int mid = (s + e) >> 1;
  updateRange(v << 1, s, mid, l, min(mid, r), val);
  updateRange(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, val);
  t[v] = (t[v << 1] | t[v << 1 | 1]);
}

long long get(int v, int s, int e, int l, int r) {
  if (l > r) return 0LL;
  if (l <= s && e <= r) return t[v];
  push(v, s, e);
  int mid = (s + e) >> 1;
  return (get(v << 1, s, mid, l, min(mid, r)) | get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r));
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    c[i] = (1LL << c[i]);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 1);
  n = 2 * n;
  build(1, 1, n);
  while (q--) {
    cin >> tp >> vp;
    if (tp == 1) {
      cin >> cp;
      updateRange(1, 1, n, tin[vp], tout[vp], (1LL << cp));
    } else if (tp == 2) {
      long long val = get(1, 1, n, tin[vp], tout[vp]);
      cout << __builtin_popcountll(val) << '\n';
    }
  }

  return 0;
}