#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
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
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    bool flag = true;
    for (int i = 2, j = 1, k = 1; i <= n; i++) {
      if (a[i] > a[j] && a[i] - a[j] >= i - j + 1) {
        cout << "YES" << '\n';
        cout << j << " " << i << '\n';
        flag = false;
        break;
      } else {
        j = i;
      }
      if (a[i] < a[k] && a[k] - a[i] >= i - k + 1) {
        cout << "YES" << '\n';
        cout << k << " " << i << '\n';
        flag = false;
        break;
      } else {
        k = i;
      }
    }
    if (flag) cout << "NO" << '\n';
  }

  return 0;
}
