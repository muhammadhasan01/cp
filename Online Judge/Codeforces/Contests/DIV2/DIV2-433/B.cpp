#include <bits/stdc++.h>

using namespace std;

long long n, k;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  if (n == k || k == 0) {
    cout << 0 << " " << 0 << '\n';
  } else if (n == k + 1) {
    cout << 1 << " " << 1 << '\n';
  } else {
    long long ans;
    if (3 * k - 1 < n) {
      ans = 2 * k;
    } else {
      ans = n - k;
    }
    cout << 1 << " " << ans << '\n';
  }

  return 0;
}