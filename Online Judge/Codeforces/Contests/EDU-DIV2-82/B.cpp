#include <bits/stdc++.h>

using namespace std;

int tc;
long long n, g, b;

long long ceil(long long n, long long k) {
  return (n + k - 1) / k;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> g >> b;
    long long need = ceil(n, 2);
    long long l = 0, r = 1e9, k = 0;
    while (l <= r) {
      long long mid = (l + r) >> 1;
      if (mid * g < need) {
        k = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    cout << max(n, k * (g + b) + (need % g == 0 ? g : need % g)) << '\n';
  }

  return 0;
}
