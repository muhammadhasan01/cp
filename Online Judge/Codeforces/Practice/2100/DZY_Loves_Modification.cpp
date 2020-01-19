#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int K = 1e6 + 5;

int n, m, k, p;
long long ans = -1e18;
int a[N][N];
multiset<long long, greater<long long>> st[2];
long long turn[K][2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k >> p;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    long long cur = 0;
    for (int j = 1; j <= m; j++) {
      cur += a[i][j];
    }
    st[0].insert(cur);
  }
  for (int j = 1; j <= m; j++) {
    long long cur = 0;
    for (int i = 1; i <= n; i++) {
      cur += a[i][j];
    }
    st[1].insert(cur);
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < 2; j++) {
      long long z = *st[j].begin();
      turn[i][j] += turn[i - 1][j] + z;
      st[j].erase(st[j].begin());
      st[j].insert(z - (1LL) * (j ? n : m) * p);
    }
  }
  for (int i = 0; i <= k; i++) {
    long long cur = turn[i][0] + turn[k - i][1] - (1LL) * i * (k - i) * p;
    ans = max(ans, cur);
  }
  cout << ans << '\n';

  return 0;
}
