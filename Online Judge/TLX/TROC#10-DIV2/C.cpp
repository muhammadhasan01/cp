#include <bits/stdc++.h>

using namespace std;

long long x[7];

long long g(long long x) {
  return x * (x + 1) / 2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 1; i <= 6; i++) {
    cin >> x[i];
  }
  cout << g(x[1] + x[2] + x[3] - 2) - (g(x[1] - 1) + g(x[3] - 1) + g(x[5] - 1)) << '\n';

  return 0;
}
