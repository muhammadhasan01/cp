#include <bits/stdc++.h>

using namespace std;

const int N = 105;

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
    int sum = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] == 0) {
        a[i] = 1;
        cnt++;
      }
      sum += a[i];
    }
    int ans = cnt;
    if (sum == 0) ans++;
    cout << ans << '\n';
  }

  return 0;
}
