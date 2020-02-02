#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  if (n == 0) {
    cout << 1 << '\n';
    return 0;
  } else if (n == 1) {
    cout << 0 << '\n';
    return 0;
  } else if (n == 2) {
    cout << 8 << '\n';
    return 0;
  }
  if (n % 2 == 0) {
    for (int i = 1; i <= n / 2; i++) {
      cout << 8;
    }
  } else {
    cout << 4;
    for (int i = 1; i <= n / 2; i++) {
      cout << 8;
    }
  }
  cout << '\n';

  return 0;
}
