#include <bits/stdc++.h>

using namespace std;

int tc;
int n;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n;
    if (n == 1) {
      cout << -1 << '\n';
      continue;
    }
    cout << 5;
    for (int i = 0; i < n - 1; i++) {
      cout << 7;
    }
    cout << '\n';
  }

  return 0;
}