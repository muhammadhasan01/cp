#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int MAXN = (1 << 17);
const int K = 19;

int n;
int a[N], dp[N];
int pre[MAXN];
int sp[MAXN][K];

int get(int i, int j) {
  int k = pre[j - i + 1];
  return max(sp[i][k], sp[j - (1 << k) + 1][k]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  pre[1] = 0;
  for (int i = 2; i < MAXN; i++) {
    pre[i] = pre[i >> 1] + 1;
  }
  for (int i = 1; i <= n; i++) {
    sp[i][0] = a[i];
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i <= n; i++) {
      sp[i][j] = max(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
    }
  }
  for (int i = n; i >= 1; i--) {
    int l = i + 1, r = n, pos = n + 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (get(i + 1, mid) > a[i]) {
        pos = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    dp[i] = 1 + dp[pos];
  }
  int cur = 0, maks = -1;
  int res = -1, ans = 1e9;
  for (int i = 1; i <= n; i++) {
    int l = i + 1, r = n, pos = n + 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (get(i + 1, mid) > maks) {
        pos = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    int curr = dp[pos] + cur;
    if (curr > res) {
      res = curr;
      ans = a[i];
    } else if (curr == res) {
      ans = min(ans, a[i]);
    }
    if (a[i] > maks) {
      cur++;
      maks = a[i];
    }
  }
  cout << ans << '\n';

  return 0;
}
