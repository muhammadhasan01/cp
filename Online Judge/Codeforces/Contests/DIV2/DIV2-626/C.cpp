#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> s;
  s = '#' + s;
  int flag = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '(') {
      flag++;
    } else {
      flag--;
    }
  }
  if (flag != 0) {
    cout << -1 << '\n';
    return 0;
  }
  int cur = 0;
  int ans = 0;
  int last = -1;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '(') {
      ++cur;
      if (cur == 0) {
        ans += (i - last + 1);
        last = -1;
      }
    } else {
      --cur;
      if (cur < 0 && last == -1) {
        last = i;
      }
    }
  }
  cout << ans << '\n';

  return 0;
}