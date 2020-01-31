#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;

int n;
int dp[N];
short int a[N];
short int le[N], ri[N];
bitset<N> vis;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (le[a[i]] == 0) le[a[i]] = i;
    ri[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    vis.reset();
    short int most_left = n + 1, most_right = 0;
    int XOR = 0;
    for (int j = i; j >= 1; j--) {
      most_left = min(most_left, le[a[j]]);
      most_right = max(most_right, ri[a[j]]);
      if (vis[a[j]] == 0) {
        XOR ^= a[j];
        vis[a[j]] = 1;
      }
      if (most_left == j && most_right == i) {
        dp[i] = max(dp[i], XOR + dp[j - 1]);
      }
    }
  }
  cout << dp[n] << '\n';

  return 0;
}
