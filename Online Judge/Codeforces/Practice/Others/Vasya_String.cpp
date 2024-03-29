#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, k;
char s[N];
int pre[N][2];

bool can(int x) {
  for (int i = 1; i <= n - x + 1; i++) {
    int cnt_a = pre[i + x - 1][0] - pre[i - 1][0];
    int cnt_b = pre[i + x - 1][1] - pre[i - 1][1];
    if (cnt_a <= k) return true;
    if (cnt_b <= k) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  cin >> (s + 1);
  for (int i = 1; i <= n; i++) {
    for (int t = 0; t < 2; t++) pre[i][t] = pre[i - 1][t];
    pre[i][s[i] - 'a']++;
  }
  int l = 1, r = n, ans = 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (can(mid)) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << ans << '\n';

  return 0;
}
