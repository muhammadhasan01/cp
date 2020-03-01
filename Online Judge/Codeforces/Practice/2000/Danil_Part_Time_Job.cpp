#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, q;
vector<int> g[N];
bool c[N];
int tin[N], tout[N], tim;
int mp[2 * N];

void dfs(int u) {
  tin[u] = ++tim;
  mp[tim] = u;
  for (auto v : g[u]) {
    dfs(v);
  }
  tout[u] = ++tim;
  mp[tim] = u;
}

struct segtreeLazy {
  int t[8 * N];
  bool lazy[8 * N];

  segtreeLazy() {
    memset(t, 0, sizeof(t));
    memset(lazy, false, sizeof(lazy));
  }

  void build(int v, int s, int e) {
    if (s == e) {
      t[v] = c[mp[s]];
      return;
    }
    int mid = (s + e) / 2;
    build(2 * v, s, mid);
    build(2 * v + 1, mid + 1, e);
    t[v] = t[2 * v] + t[2 * v + 1];
  }

  void push(int v, int s, int e) {
    if (!lazy[v] || s == e) return;
    int mid = (s + e) / 2;
    t[2 * v] = (mid - s + 1) - t[2 * v];
    t[2 * v + 1] = (e - (mid + 1) + 1) - t[2 * v + 1];
    lazy[2 * v] ^= lazy[v];
    lazy[2 * v + 1] ^= lazy[v];
    lazy[v] = 0;
  }

  void updateRange(int v, int s, int e, int l, int r) {
    if (l > r) return;
    if (l == s && e == r) {
      t[v] = (e - s + 1) - t[v];
      lazy[v] ^= 1;
      return;
    }
    push(v, s, e);
    int mid = (s + e) / 2;
    updateRange(2 * v, s, mid, l, min(r, mid));
    updateRange(2 * v + 1, mid + 1, e, max(l, mid + 1), r);
    t[v] = t[2 * v] + t[2 * v + 1];
  }

  int get(int v, int s, int e, int l, int r) {
    if (l > r) return 0;
    if (l <= s && e <= r) return t[v];
    push(v, s, e);
    int mid = (s + e) / 2;
    return get(2 * v, s, mid, l, min(r, mid)) + get(2 * v + 1, mid + 1, e, max(l, mid + 1), r);
  }
};

segtreeLazy strl;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    g[x].push_back(i);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  n = 2 * n;
  strl.build(1, 1, n);
  cin >> q;
  while (q--) {
    string s;
    int tp;
    cin >> s >> tp;
    if (s[0] == 'g') {
      cout << strl.get(1, 1, n, tin[tp], tout[tp]) / 2 << '\n';
    } else if (s[0] == 'p') {
      strl.updateRange(1, 1, n, tin[tp], tout[tp]);
    }
  }

  return 0;
}