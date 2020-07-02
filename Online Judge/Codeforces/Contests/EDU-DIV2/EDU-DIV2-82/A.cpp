#include <bits/stdc++.h>

using namespace std;

int tc;
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> s;
    int n = s.length();
    int x = 0, y = n;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        y = min(y, i);
        x = i;
      }
    }
    int ans = 0;
    for (int i = y; i <= x; i++) {
      if (s[i] == '0') ans++;
    }
    cout << ans << '\n';
  }

  return 0;
}
