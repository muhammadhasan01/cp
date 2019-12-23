#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n / 2; i++) {
    for (int j = 1; j <= m; j++) {
      cout << i << " " << j << '\n';
      cout << n + 1 - i << " " << m + 1 - j << '\n';
    }
  }
  if (n & 1) {
    n = (n + 1) / 2;
    for (int i = 1; i <= m / 2; i++) {
      cout << n << " " << i << '\n';
      cout << n << " " << m + 1 - i << '\n';
    }
    if (m & 1) cout << n << " " << (m + 1) / 2 << '\n';
  }

  return 0;
}
