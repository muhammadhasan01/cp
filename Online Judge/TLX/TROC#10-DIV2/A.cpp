#include <bits/stdc++.h>

using namespace std;

string s, t;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s >> t;
  bool flag = false;
  for (int i = 0; i < (int) s.size(); i++) {
    if (tolower(s[i]) != tolower(t[i])) {
      flag = true;
      break;
    }
  }
  puts(flag ? "x_x" : "20/20");

  return 0;
}
