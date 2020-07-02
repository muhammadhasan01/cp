#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

int tc;
int n;
int a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n;
    int odd = 0, even = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (x & 1) odd++;
      else even++;
    }
    cout << (odd & 1 || (odd % 2 == 0 && odd > 0 && even > 0) ? "YES" : "NO") << '\n';
  }

  return 0;
}
