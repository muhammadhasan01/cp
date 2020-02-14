#include <bits/stdc++.h>

using namespace std;

const int N = 4000;
const int INF = 2e9;

int tc;
int n, m, k;
int a[N], dp[N];
int t[4 * N];

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

int get(int v, int s, int e, int l, int r) {
  if (e < l || s > r) return INF;
  if (l <= s && e <= r) return t[v];
  int mid = (s + e) >> 1;
  return min(get(v << 1, s, mid, l, r), get(v << 1 | 1, mid + 1, e, l, r));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> m >> k;
    k = min(m - 1, k);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int len_sub = n - m + 1;
    for (int i = 1; i <= n - len_sub + 1; i++) {
      dp[i] = max(a[i], a[i + len_sub - 1]);
    }
    build(1, 1, n);
    int len = n - k;
    int ans = 0;
    for (int i = 1; i <= n - len + 1; i++) {
      int cur = get(1, 1, n, i, i + len - len_sub);
      ans = max(ans, cur);
    }
    cout << ans << '\n';
  }

  return 0;
}
