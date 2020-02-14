#include <bits/stdc++.h>

using namespace std;

int tc;
int s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> s;
    int ans = 0;
    do {
      ans += 10 * (s / 10);
      s = (s % 10) + (s / 10);
    } while (s >= 10);
    ans += s;
    cout << ans << '\n';
  }

  return 0;
}
