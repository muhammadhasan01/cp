#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long INF = 1e18;

int n;
int p[N], a[N];
int pos[N];
long long dp[N];
long long pre[N];
long long ans = INF;

long long lazy[4 * N], t[4 * N];

void build(int v, int s, int e) {
  if (s == e) {
    t[v] = dp[s];
  } else {
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    t[v] = min(t[v << 1], t[v << 1 | 1]);
  }
}

void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, long long addend) {
    if (l > r)
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

long long query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return INF;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm)),
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    pos[p[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + a[pos[i]];
  }
  for (int i = 0; i <= n; i++) {
    dp[i] = pre[i] + (p[1] > i ? a[1] : -a[1]);
    ans = min(ans, dp[i]);
  }
  build(1, 0, n);
  for (int i = 2; i <= n - 1; i++) {
    update(1, 0, n, 0, p[i] - 1, a[i]);
    update(1, 0, n, p[i], n, -a[i]);
    ans = min(ans, query(1, 0, n, 0, n));
  }
  cout << ans << '\n';

  return 0;
}
