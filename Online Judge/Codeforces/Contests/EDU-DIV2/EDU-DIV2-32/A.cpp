#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
int n;
int a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 2; i <= n - 1; i++) {
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) ans++;
    else if (a[i] < a[i - 1] && a[i] < a[i + 1]) ans++;
  }
  cout << ans << '\n';

  return 0;
}
