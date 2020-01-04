#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
int n, q;
int a[N], t[4 * N];

void build(int v, int s, int e) {
  if (s == e) {
    t[v] = a[s];
  } else {
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    t[v] = __gcd(t[v << 1], t[v << 1 | 1]);
  }
}

void update(int v, int s, int e, int pos, int val) {
  if (s == e) {
    t[v] = val;
  } else {
    int mid = (s + e) >> 1;
    if (pos <= mid) {
      update(v << 1, s, mid, pos, val);
    } else {
      update(v << 1 | 1, mid + 1, e, pos, val);
    }
    t[v] = __gcd(t[v << 1], t[v << 1 | 1]);
  }
}

void get(int v, int s, int e, int l, int r, int x, int &ret) {
  if (e < l || s > r) return;
  if (l <= s && e <= r) {
    if (t[v] % x == 0) return;
    while (s < e) {
      int mid = (s + e) >> 1;
      if (t[v << 1] % x != 0) {
        if (t[v << 1 | 1] % x != 0) {
          ret += 2;
          return;
        }
        v = (v << 1);
        e = mid;
      } else {
        v = (v << 1 | 1);
        s = mid + 1;
      }
    }
    ret++;
    return;
  }
  int mid = (s + e) >> 1;
  get(v << 1, s, mid, l, r, x, ret);
  if (ret > 1) return;
  get(v << 1 | 1, mid + 1, e, l, r, x, ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  cin >> q;
  int t, l, r, x, i, y;
  while (q--) {
    cin >> t;
    if (t == 1) {
      cin >> l >> r >> x;
      int ans = 0;
      get(1, 1, n, l, r, x, ans);
      cout << (ans <= 1 ? "YES" : "NO") << '\n';
    } else if (t == 2) {
      cin >> i >> y;
      update(1, 1, n, i, y);
    }
  }

  return 0;
}
