#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int n;
long long a[N];
long long ans[N];
long long dp[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  int i = 1, j = n + 1;
  dp[1] = -a[1];
  int k = 2;
  while (k <= n) {
    dp[k] = dp[k - 1];
    if (k & 1) {
      dp[k] -= a[++i];
    } else {
      dp[k] += a[--j];
    }
    ans[k] = ans[k - 1] + dp[k - 1] + (k % 2 == 0 ? a[j] : 0);
    k++;
  }
  for (int i = 2; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
