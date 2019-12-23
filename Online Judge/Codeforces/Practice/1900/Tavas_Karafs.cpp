#include <bits/stdc++.h>

using namespace std;

const long long INF = 2e6 + 5;
long long A, B, q;
long long l, t, m;

long long get(long long x, long long y) {
  long long sum = (y * (y - 1) - x * (x - 1)) / 2;
  return A * (y - x) + sum * B;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> A >> B >> q;
  while (q--) {
    cin >> l >> t >> m;
    long long le = l, ri = INF, ans = l;
    while (le <= ri) {
      long long mid = (le + ri) >> 1;
      if (A + (mid - 2) * B <= t && get(l - 1, mid - 1) <= t * m) {
        ans = mid;
        le = mid + 1;
      } else {
        ri = mid - 1;
      }
    }
    if (ans == l) ans = 0;
    cout << ans - 1 << '\n';
  }

  return 0;
}
