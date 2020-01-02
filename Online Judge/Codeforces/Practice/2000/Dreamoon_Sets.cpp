#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  cout << (6 * (n - 1) + 5) * k << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= 4; j++) {
      if (j == 4) j++;
      cout << (6 * i + j) * k << (j == 5 ? '\n' : ' ');
    }
  }

  return 0;
}
