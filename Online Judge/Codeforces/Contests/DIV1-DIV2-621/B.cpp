#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

int tc;
int n;
long long x;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> x;
    long long ans = INF;
    long long maks = 0;
    for (int i = 1; i <= n; i++) {
      long long y = 0;
      cin >> y;
      maks = max(maks, y);
      if (x % y == 0) {
        ans = min(ans, x / y);
      }
    }
    long long l = 0, r = 1e9 + 100, best = 0;
    while (l <= r) {
      long long mid = (l + r) >> 1;
      if (x - mid * maks <= 2 * maks) {
        r = mid - 1;
        best = mid;
      } else {
        l = mid + 1;
      }
    }
    ans = min(ans, best + 2);
    cout << ans << '\n';
  }

  return 0;
}