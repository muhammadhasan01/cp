#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct st {
  long long x, v;
  bool operator<(const st& ot) {
    if (x == ot.x) return v < ot.v;
    return x < ot.x;
  }
};

int n;
st a[N];
vector<int> t[4 * N];

void build(int v, int s, int e) {
  if (s == e) {
    t[v] = vector<int>(1, a[s].v);
    return;
  }
  int mid = (s + e) / 2;
  build(2 * v, s, mid);
  build(2 * v + 1, mid + 1, e);
  merge(t[2 * v].begin(), t[2 * v].end(), t[2 * v + 1].begin(),
    t[2 * v + 1].end(), back_inserter(t[v]));
}

int get(int v, int s, int e, int l, int r, int x, bool tp) {
  if (e < l || s > r) return 0;
  if (l <= s && e <= r) {
    if (tp) {
      int ret = upper_bound(t[v].begin(), t[v].end(), x) - t[v].begin();
      return ret;
    } else {
      int ret = t[v].end() - lower_bound(t[v].begin(), t[v].end(), x);
      return ret;
    }
  }
  int mid = (s + e) / 2;
  return get(2 * v, s, mid, l, r, x, tp) + get(2 * v + 1, mid + 1, e, l, r, x, tp);
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].v;
  }
  sort(a + 1, a + 1 + n);
  build(1, 1, n);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int l = i + 1, r = n, pos = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (a[mid].x > a[i].x) {
        r = mid - 1;
        pos = mid;
      } else {
        l = mid + 1;
      }
    }
    if (pos != -1) {
      long long cnt = get(1, 1, n, pos, n, a[i].v, 0);
      ans -= cnt * a[i].x;
    }
    l = 1, r = i - 1, pos = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (a[mid].x < a[i].x) {
        l = mid + 1;
        pos = mid;
      } else {
        r = mid - 1;
      }
    }
    if (pos == -1) continue;
    long long cnt = get(1, 1, n, 1, pos, a[i].v, 1);
    ans += cnt * a[i].x;
  }
  cout << ans << '\n';

  return 0;
}