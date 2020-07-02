#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc, n;
int a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + 1 + 2 * n);
    cout << a[n + 1] - a[n] << '\n';
  }

  return 0;
}
