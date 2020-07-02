#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct st {
  int a, b, idx;
  bool operator<(const st& other) {
    return (a - b < other.a - other.b);
  }
  int f() {
    return (a - b);
  }
};

int n;
st p[N];
vector<int> t[4 * N];

void build(int v, int s, int e) {
  if (s == e) {
    t[v] = vector<int>(1, p[s].f());
    return;
  }
  int mid = (s + e) >> 1;
  build(v << 1, s, mid);
  build(v << 1 | 1, mid + 1, e);
  merge(t[v << 1].begin(), t[v << 1].end(), t[v << 1 | 1].begin(), t[v << 1 | 1].end(),
    back_inserter(t[v]));
}

int get(int v, int s, int e, int l, int r, int x) {
  if (e < l || s > r) return 0;
  if (l <= s && e <= r) {
    int ret = t[v].end() - upper_bound(t[v].begin(), t[v].end(), x);
    return ret;
  }
  int mid = (s + e) >> 1;
  return get(v << 1, s, mid, l, r, x) + get(v << 1 | 1, mid + 1, e, l, r, x);
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].a;
    p[i].idx = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> p[i].b;
  }
  build(1, 1, n);
  long long ans = 0;
  for (int i = 1; i <= n - 1; i++) {
    ans += get(1, 1, n, i + 1, n, -p[i].f());
  }
  cout << ans << '\n';

  return 0;
}