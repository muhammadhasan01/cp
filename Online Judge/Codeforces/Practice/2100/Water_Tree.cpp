#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n, q;
vector<int> g[N];
int eul[2 * N];
int tin[N], tout[N], tim;
pair<int, int> p[N];

struct segtree_lazy {
  int t[8 * N], lazy[8 * N];

  segtree_lazy() {
    memset(t, 0, sizeof(t));
    memset(lazy, 0, sizeof(lazy));
  }

  void push(int v) {
    if (lazy[v] == 0) return;
    t[2 * v] = lazy[v];
    t[2 * v + 1] = lazy[v];
    lazy[2 * v] = lazy[v];
    lazy[2 * v + 1] = lazy[v];
    lazy[v] = 0;
  }

  void updateRange(int v, int s, int e, int l, int r, int val) {
    if (l > r) return;
    if (l == s && e == r) {
      t[v] = val;
      lazy[v] = val;
      return;
    }
    push(v);
    int mid = (s + e) / 2;
    updateRange(2 * v, s, mid, l, min(mid, r), val);
    updateRange(2 * v + 1, mid + 1, e, max(l, mid + 1), r, val);
    t[v] = max(t[2 * v], t[2 * v + 1]);
  }

  int get(int v, int s, int e, int l, int r) {
    if (l > r) return 0;
    if (l <= s && e <= r) return t[v];
    push(v);
    int mid = (s + e) / 2;
    int p1 = get(2 * v, s, mid, l, min(mid, r));
    int p2 = get(2 * v + 1, mid + 1, e, max(mid + 1, l), r);
    return max(p1, p2);
  }

  void upd(int l, int r, int val) {
    updateRange(1, 1, 2 * n, l, r, val);
  }

  int query(int l, int r) {
    return get(1, 1, 2 * n, l, r);
  }

};

struct segtree {
  int t[8 * N];

  void update(int v, int s, int e, int pos, int val) {
    if (s == e) {
      t[v] = val;
      return;
    }
    int mid = (s + e) / 2;
    if (pos <= mid) update(2 * v, s, mid, pos, val);
    else if (pos > mid) update(2 * v + 1, mid + 1, e, pos, val);
    t[v] = max(t[2 * v], t[2 * v + 1]);
  }

  int get(int v, int s, int e, int l, int r) {
    if (l > r) return 0;
    if (l <= s && e <= r) return t[v];
    int mid = (s + e) / 2;
    int p1 = get(2 * v, s, mid, l, min(mid, r));
    int p2 = get(2 * v + 1, mid + 1, e, max(mid + 1, l), r);
    return max(p1, p2);
  }

  void upd(int pos, int val) {
    update(1, 1, 2 * n, pos, val);
  }

  int query(int l, int r) {
    return get(1, 1, 2 * n, l, r);
  }

};

segtree_lazy stl;
segtree st;

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
  p[0] = {2, 0};
  for (int i = 1; i <= q; i++) {
    int t, x;
    cin >> t >> x;
    p[i] = {t, x};
    if (t == 1) {
      stl.upd(tin[x], tout[x], i);
    } else if (t == 2) {
      st.upd(tin[x], i);
    } else if (t == 3) {
      int mks = max(stl.query(tin[x], tin[x]), st.query(tin[x], tout[x]));
      cout << (p[mks].first == 1 ? 1 : 0) << '\n';
    }
  }

  return 0;
}
