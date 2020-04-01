#include <bits/stdc++.h>

using namespace std;

long long n, k;
long long p = 1, x = 1, ans = 1;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  k = min(k, n - k);
  for (int i = 1; i <= n; i++) {
    if (p <= n && p + k > n + 1) {
      x++;
      ans += x;
      x++;
    } else {
      ans += x;
    }
    p += k;
    if (p > n) p -= n;
    cout << ans << (i == n ? '\n' : ' ');
  }

  return 0;
}