#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> s;
  int ans = 0;
  int x = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] > 'z' || s[i] < 'a') {
      cout << 0 << '\n';
      return 0;
    }
    if (s[i] == 'h') {
      x++;
    } else {
      ans += (x >= 3 ? x - 2 : 0);
      x = 0;
    }
  }
  ans += (x >= 3 ? x - 2 : 0);
  cout << ans << '\n';

  return 0;
}