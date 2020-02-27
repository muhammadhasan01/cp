#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct st {
  int val;
  long long tim;
  bool operator<(const st& other) {
    return val < other.val;
  }
};

struct node {
  long long sum, maks;
  int idx;
  friend node merge(const node& a, const node& b) {
    node ret;
    ret.sum = a.sum + b.sum;
    ret.maks = max(a.maks, b.maks);
    ret.idx = (a.maks >= b.maks ? a.idx : b.idx);
    return ret;
  }
};

int n;
st a[N];
node t[4 * N];

void build(int v, int s, int e) {
  if (s == e) {
    t[v] = {a[s].tim, a[s].tim, s};
    return;
  }
  int mid = (s + e) / 2;
  build(2 * v, s, mid);
  build(2 * v + 1, mid + 1, e);
  t[v] = merge(t[2 * v], t[2 * v + 1]);
}

void update(int v, int s, int e, int pos, int val) {
  if (s == e && s == pos) {
    t[v] = {val, val, s};
    return;
  }
  int mid = (s + e) / 2;
  if (pos <= mid) {
    update(2 * v, s, mid, pos, val);
  } else {
    update(2 * v + 1, mid + 1, e, pos, val);
  }
  t[v] = merge(t[2 * v], t[2 * v + 1]);
}

node get(int v, int s, int e, int l, int r) {
  if (e < l || s > r) return {0LL, 0LL, -1};
  if (l <= s && e <= r) return t[v];
  int mid = (s + e) / 2;
  return merge(get(2 * v, s, mid, l, r), get(2 * v + 1, mid + 1, e, l, r));
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].val;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].tim;
  }
  sort(a + 1, a + 1 + n);
  build(1, 1, n);
  long long now = a[1].val;
  long long res = 0;
  for (int i = 1; i < n; i++) {
    int l = i + 1, r = n, pos = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (a[mid].val <= now) {
        l = mid + 1;
        pos = mid;
      } else {
        r = mid - 1;
      }
    }
    if (pos == -1) {
      now = a[i + 1].val;
    } else {
      now++;
      node u = get(1, 1, n, i, pos);
      res += u.sum - u.maks;
      int at = u.idx;
      if (at == i) continue;
      update(1, 1, n, at, a[i].tim);
      update(1, 1, n, i, u.maks);
      long long temp = a[i].tim;
      a[i].tim = a[at].tim;
      a[at].tim = temp;
    }
  }
  cout << res << '\n';

  return 0;
}