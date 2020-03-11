#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, q;
string str;
string pat = "abcdefghijklmnopqrstuvwxyz";

int t[4 * N][30], lazy[4 * N][30];

void build(int v, int p, int s, int e) {
  if (s == e) {
    t[v][p] = (str[s - 1] == pat[p]);
    lazy[v][p] = -1;
    return;
  }
  int mid = (s + e) >> 1;
  build(v << 1, p, s, mid);
  build(v << 1 | 1, p, mid + 1, e);
  t[v][p] = t[v << 1][p] + t[v << 1 | 1][p];
  lazy[v][p] = -1;
}

void push(int v, int p, int s, int e) {
  if (lazy[v][p] == -1 || s == e) return;
  int mid = (s + e) >> 1;
  lazy[v << 1][p] = lazy[v][p];
  lazy[v << 1 | 1][p] = lazy[v][p];
  t[v << 1][p] = (mid - s + 1) * lazy[v][p];
  t[v << 1 | 1][p] = (e - mid) * lazy[v][p];
  lazy[v][p] = -1;
}

void updateRange(int v, int p, int s, int e, int l, int r, int val) {
  if (l > r) return;
  if (l == s && e == r) {
    t[v][p] = (e - s + 1) * val;
    lazy[v][p] = val;
    return;
  }
  push(v, p, s, e);
  int mid = (s + e) >> 1;
  updateRange(v << 1, p, s, mid, l, min(r, mid), val);
  updateRange(v << 1 | 1, p, mid + 1, e, max(l, mid + 1), r, val);
  t[v][p] = t[v << 1][p] + t[v << 1 | 1][p];
}

int get(int v, int p, int s, int e, int l, int r) {
  if (l > r) return 0;
  if (l <= s && e <= r) return t[v][p];
  push(v, p, s, e);
  int mid = (s + e) >> 1;
  return get(v << 1, p, s, mid, l, min(r, mid)) + get(v << 1 | 1, p, mid + 1, e, max(l, mid + 1), r);
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> q >> str;
  for (int i = 0; i < 26; i++) {
    build(1, i, 1, n);
  }
  while (q--) {
    int l, r, tp;
    cin >> l >> r >> tp;
    if (tp == 1) {
      int offset = 0;
      for (int i = 0; i < 26; i++) {
        int tmp = get(1, i, 1, n, l, r);
        if (tmp == 0) continue;
        updateRange(1, i, 1, n, l, r, 0);
        updateRange(1, i, 1, n, l + offset, l + offset + tmp - 1, 1);
        offset += tmp;
      }
    } else {
      int offset = 0;
      for (int i = 0; i < 26; i++) {
        int tmp = get(1, i, 1, n, l, r);
        if (tmp == 0) continue;
        updateRange(1, i, 1, n, l, r, 0);
        updateRange(1, i, 1, n, r - offset - tmp + 1, r - offset, 1);
        offset += tmp;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 26; j++) {
      int x = get(1, j, 1, n, i, i);
      if (x == 0) continue;
      cout << pat[j];
      break;
    }
  }

  return 0;
}