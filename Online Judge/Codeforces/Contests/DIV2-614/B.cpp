#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  ld cur = 0;
  for (ld i = 1; i <= n; i++) {
    cur += 1.0 / i;
  }
  cout << fixed << setprecision(12) << cur << '\n';

  return 0;
}
