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
    if (n % 2 == 0) {
      for (int i = 1; i <= n / 2; i++) {
        cout << 1;
      }
    } else {
      cout << 7;
      for (int i = 1; i <= (n - 1) / 2 - 1; i++) {
        cout << 1;
      }
    }
    cout << '\n';
  }

  return 0;
}
