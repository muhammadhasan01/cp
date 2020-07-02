#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n + 3, vector<int>(m + 3));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> v[i][j];
    }
  }
  long long ans = 0;
  for (int i = 1; i <= m; i++) {
    vector<long long> cnt(n + 5, n);
    for (int j = 1; j <= n; j++) {
      if (v[j][i] % m == i % m) {
        int ord = (v[j][i] - i) / m + 1;
        if (ord < 1 || ord > n) continue;
        int pos = j - ord + 1;
        if (pos <= 0) pos += n;
        cnt[pos]--;
      }
    }
    long long cur = INF;
    for (long long j = 1; j <= n; j++) {
      cur = min(cur, j - 1 + cnt[j]);
    }
    ans += cur;
  }
  cout << ans << '\n';

  return 0;
}
