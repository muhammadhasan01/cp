#include <bits/stdc++.h>

using namespace std;

int tc;
long long a, b;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> a >> b;
    if (a == b) {
      cout << 0 << '\n';
    } else if (a < b && (b - a) % 2 == 1) {
      cout << 1 << '\n';
    } else if (a > b && (a - b) % 2 == 0) {
      cout << 1 << '\n';
    } else {
      cout << 2 << '\n';
    }
  }

  return 0;
}