#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;

int n, k;
int ans;
int a[N];
int dp[N][N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    int l = 1, r = i - 1, best = i - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (a[mid] >= a[i] - 5) {
        r = mid - 1;
        best = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    for (int j = 1; j <= k; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[best][j - 1] + i - best);
      if (j == k) ans = max(ans, dp[i][k]);
    }
  }
  cout << ans << '\n';

  return 0;
}