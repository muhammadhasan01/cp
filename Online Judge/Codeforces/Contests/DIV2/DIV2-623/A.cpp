#include <bits/stdc++.h>

using namespace std;

int tc;
int a, b, x, y;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> a >> b >> x >> y;
    x++, y++;
    int ans = 0;
    ans = max(ans, (x - 1) * b);
    ans = max(ans, (y - 1) * a);
    ans = max(ans, (a - x) * b);
    ans = max(ans, (b - y) * a);
    cout << ans << '\n';
  }

  return 0;
}