#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

int n;
int a[N];
int t[4 * N];

void build(int v, int s, int e) {
  if (s == e) {
    t[v] = a[s];
    return;
  }
  int mid = (s + e) / 2;
  build(2 * v, s, mid);
  build(2 * v + 1, mid + 1, e);
  t[v] = __gcd(t[2 * v], t[2 * v + 1]);
}

int get(int v, int s, int e, int l, int r) {
  if (e < l || s > r) return 0;
  if (l <= s && e <= r) return t[v];
  int mid = (s + e) / 2;
  return __gcd(get(2 * v, s, mid, l, r), get(2 * v + 1, mid + 1, e, l, r));
}

bool can(int k) {
  for (int i = 1; i <= n - k + 1; i++) {
    if (get(1, 1, n, i, i + k - 1) == 1) return true;
  }
  return false;
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  int g = 0;
  bool flag = false;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    g = __gcd(g, a[i]);
    if (a[i] == 1) {
      flag = true;
    }
  }
  if (g != 1) {
    cout << -1 << '\n';
    return 0;
  }
  if (flag) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] != 1) ans++;
    }
    cout << ans << '\n';
    return 0;
  }
  build(1, 1, n);
  int l = 1, r = n;
  int best = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (can(mid)) {
      r = mid - 1;
      best = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << best + n - 2 << '\n';

  return 0;
}