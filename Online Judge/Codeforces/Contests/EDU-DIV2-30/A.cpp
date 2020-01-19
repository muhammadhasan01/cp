#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n, k, x;
int a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  reverse(a + 1, a + 1 + n);
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    ans += min(a[i], x);
  }
  for (int i = k + 1; i <= n; i++) {
    ans += a[i];
  }
  cout << ans << '\n';

  return 0;
}
