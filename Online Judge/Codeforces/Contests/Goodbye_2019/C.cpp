#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int tc;
int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n;
    long long xr = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
      int y;
      cin >> y;
      xr ^= y;
      sum += y;
    }
    cout << 3 << '\n';
    cout << xr << " " << xr + sum << " " << 0 << '\n';
  }

  return 0;
}
