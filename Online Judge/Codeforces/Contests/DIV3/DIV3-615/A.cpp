#include <bits/stdc++.h>

using namespace std;

int tc;
long long x[3], n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> x[0] >> x[1] >> x[2] >> n;
    sort(x, x + 3);
    long long res = x[2] - x[1] + x[2] - x[0];
    cout << (res <= n && (n - res) % 3 == 0 ? "YES" : "NO") << '\n';
  }

  return 0;
}
