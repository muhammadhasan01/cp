#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int L = (1 << 17);
int n, x;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> x;
  if (n == 1) {
    cout << "YES" << '\n';
    cout << x << '\n';
  } else if (n == 2) {
    if (x == 0) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
      cout << 0 << " " << x  << '\n';
    }
  } else {
    cout << "YES" << '\n';
    int y = 0;
    for (int i = 1; i <= n - 3; i++) {
      cout << i << " ";
      y = (y ^ i);
    }
    if (y == x) {
      cout << L << " " << (L << 1) << " " << (L ^ (L << 1)) << '\n';
    } else {
      cout << 0 << " " << L << " " << ((L ^ y) ^ x) << '\n';
    }
  }

  return 0;
}
