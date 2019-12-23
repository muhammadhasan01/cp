#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
int n;
int s[N];
int a[4 * N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  int g = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    g = __gcd(g, s[i]);
  }
  if (g != s[1]) {
    cout << -1 << '\n';
    return 0;
  }
  cout << 2 * n - 1 << '\n';
  cout << s[1] << (2 * n - 1 == n ? '\n' : ' ');
  for (int i = 2; i <= n; i++) {
    cout << s[1] << " " << s[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
