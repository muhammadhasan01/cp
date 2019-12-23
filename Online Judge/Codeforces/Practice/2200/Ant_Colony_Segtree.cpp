#include <bits/stdc++.h>

using namespace std;

struct st {
  int g, mins, cnt;
};

const int N = 1e5 + 5;
const int INF = 2e9;
int n;
int a[N];
int tc;
st t[4 * N];

st merge(st a, st b) {
  int retg = __gcd(a.g, b.g);
  int retm, retcnt;
  if (a.mins < b.mins) {
    retm = a.mins;
    retcnt = a.cnt;
  } else if (a.mins > b.mins) {
    retm = b.mins;
    retcnt = b.cnt;
  } else {
    retm = a.mins;
    retcnt = a.cnt + b.cnt;
  }
  return {retg, retm, retcnt};
}

void build(int v, int s, int e) {
  if (s == e) {
    t[v] = {a[s], a[s], 1};
  } else {
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    t[v] = merge(t[v << 1], t[v << 1 | 1]);
  }
}

st query(int v, int s, int e, int l, int r) {
  if (s > r || e < l) {
    return {0, INF, 1};
  }
  if (l <= s && e <= r) {
    return t[v];
  }
  int mid = (s + e) >> 1;
  return merge(query(v << 1, s, mid, l, r), query(v << 1 | 1, mid + 1, e, l, r));
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
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    int l, r;
    cin >> l >> r;
    int ans = r - l + 1;
    st res = query(1, 1, n, l, r);
    if (res.g == res.mins) {
      ans -= res.cnt;
    }
    cout << ans << '\n';
  }

  return 0;
}
