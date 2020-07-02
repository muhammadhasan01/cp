#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int tc;
int n, k1, k2;
int a[N], b[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> k1 >> k2;
    for (int i = 1; i <= k1; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= k2; i++) {
      cin >> b[i];
    }
    sort(a + 1, a + 1 + k1);
    sort(b + 1, b + 1 + k2);
    cout << (a[k1] > b[k2] ? "YES" : "NO") << '\n';
  }

  return 0;
}
