#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

int a, b, c;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> a >> b >> c;
  for (int i = 1; i < N; i++) {
    if (((a * 10) / b) % 10 == c) {
      cout << i << '\n';
      return 0;
    }
    a = (a * 10) % b;
  }
  cout << -1 << '\n';

  return 0;
}
