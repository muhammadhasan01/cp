#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;
const int T = 2e3 + 5;

struct item {
  int t, d, p, idx;
  bool operator<(const item& x) {
    return (d < x.d);
  }
};

int n;
item a[N];
int dp[N][T];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].t >> a[i].d >> a[i].p;
    a[i].idx = i;
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < T; j++) {
      if (j == a[i].d) break;
      dp[i][j] = dp[i - 1][j];
      if (j < a[i].d && j - a[i].t >= 0) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].t] + a[i].p);
      }
    }
  }
  int ans = 0;
  int pos = 0;
  for (int i = 0; i < T; i++) {
    if (dp[n][i] > ans) {
      ans = dp[n][i];
      pos = i;
    }
  }
  cout << ans << '\n';
  deque<int> res;
  int cur = n;
  while (cur > 0) {
    if (dp[cur][pos] == dp[cur - 1][pos]) {
      cur--;
    } else if (dp[cur][pos] == dp[cur - 1][pos - a[cur].t] + a[cur].p) {
      res.push_front(a[cur].idx);
      pos -= a[cur].t;
      cur--;
    }
  }
  cout << res.size() << '\n';
  for (auto e : res) cout << e << ' ';
  cout << '\n';

  return 0;
}
