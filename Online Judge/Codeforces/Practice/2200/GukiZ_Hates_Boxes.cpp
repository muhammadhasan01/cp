#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

int n, m;
long long t[N], a[N];

bool can(long long x) {
  for (int i = 1; i <= n; i++) {
    a[i] = t[i];
  }
  int pos = n;
  for (int i = 1; i <= m; i++) {
    while (pos >= 1 && a[pos] == 0) pos--;
    if (pos == 0) break;
    long long cur = x - (1LL) * pos;
    if (cur <= 0) break;
    while (pos >= 1 && cur >= a[pos]) cur -= a[pos--];
    a[pos] -= cur;
  }
  return (pos < 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  long long l = 0, r = INF, ans = 0;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (can(mid)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';

  return 0;
}
