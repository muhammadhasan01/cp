#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int INF = 2e9 + 10;
int tc;
int n, p, k;
int a[N], pre[N];
int dp[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> p >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pre[i] = a[i] + pre[i - 1];
      dp[i] = 0;
    }
    sort(a + 1, a + 1 + n);
    dp[1] = a[1];
    for (int i = 2; i <= n; i++) {
      if (i < k) {
        dp[i] += a[i] + dp[i - 1];
      } else if (i == k) {
        dp[i] = a[i];
      } else {
        dp[i] = a[i] + dp[i - k];
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (p >= dp[i]) ans = i;
    }
    cout << ans << '\n';
  }

  return 0;
}
