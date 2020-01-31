#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct node {
  long long sum, mxm;
  node() : sum(0LL), mxm(0LL) {};
  node(long long s, long long m) : sum(s), mxm(m) {};
  friend node merge(const node& a, const node& b) {
    return node(a.sum + b.sum, max(a.mxm, b.mxm));
  }
  bool operator%=(const int& x) {
    sum %= x;
    mxm %= x;
  }
};

int n, m;
int a[N];
node t[4 * N];

void build(int v, int s, int e) {
  if (s == e) {
    t[v] = node(a[s], a[s]);
  } else {
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    t[v] = merge(t[v << 1], t[v << 1 | 1]);
  }
}

void update(int v, int s, int e, int pos, int val) {
  if (s == e) {
    t[v] = node(val, val);
  } else {
    int mid = (s + e) >> 1;
    if (pos <= mid) {
      update(v << 1, s, mid, pos, val);
    } else {
      update(v << 1 | 1, mid + 1, e, pos, val);
    }
    t[v] = merge(t[v << 1], t[v << 1 | 1]);
  }
}

void updateRange(int v, int s, int e, int l, int r, int x) {
  if (e < l || s > r) return;
  if (l <= s && e <= r && t[v].mxm < x) return;
  if (s == e) {
    t[v] %= x;
    return;
  }
  int mid = (s + e) >> 1;
  updateRange(v << 1, s, mid, l, r, x);
  updateRange(v << 1 | 1, mid + 1, e, l, r, x);
  t[v] = merge(t[v << 1], t[v << 1 | 1]);
}

long long get(int v, int s, int e, int l, int r) {
  if (e < l || s > r) return 0LL;
  if (l <= s && e <= r) return t[v].sum;
  int mid = (s + e) >> 1;
  return get(v << 1, s, mid, l, r) + get(v << 1 | 1, mid + 1, e, l, r);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  while (m--) {
    int t, l, r, x;
    cin >> t;
    if (t == 1) {
      cin >> l >> r;
      cout << get(1, 1, n, l, r) << '\n';
    } else if (t == 2) {
      cin >> l >> r >> x;
      updateRange(1, 1, n, l, r, x);
    } else if (t == 3) {
      cin >> l >> x;
      update(1, 1, n, l, x);
    }
  }

  return 0;
}
