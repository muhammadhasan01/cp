#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int INF = 2e9;

int n;
int k;
int c[N];
int ans[N];
pair<int, int> t[4 * N];
long long res = 0;

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
  return (a.first > b.first ? a : b);
}

void build(int v, int s, int e) {
  if (s == e) {
    t[v] = {c[s], s};
  } else {
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    t[v] = merge(t[v << 1], t[v << 1 | 1]);
  }
}

void update(int v, int s, int e, int pos, int val) {
  if (s == e && s == pos) {
    t[v].first = val;
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

pair<int, int> get(int v, int s, int e, int l, int r) {
  if (e < l || s > r) return make_pair(-INF, 0);
  if (l <= s && e <= r) {
    return t[v];
  }
  int mid = (s + e) >> 1;
  return merge(get(v << 1, s, mid, l, r), get(v << 1 | 1, mid + 1, e, l, r));
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    int right = min(n, k + i);
    pair<int, int> cur = get(1, 1, n, 1, right);
    res += (1LL) * ((k + i) - cur.second) * (1LL) * (cur.first);
    ans[cur.second] = k + i;
    update(1, 1, n, cur.second, -INF);
  }
  cout << res << '\n';
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}