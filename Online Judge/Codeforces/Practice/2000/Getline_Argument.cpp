#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  getline(cin, s);
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == ' ') continue;
    cout << "<";
    bool flag = false;
    if (s[i] == '\"') {
      flag = true;
      i++;
    }
    for ( ; i < (int) s.size(); i++) {
      if ((!flag && s[i] == ' ') || (flag && s[i] == '\"')) break;
      cout << s[i];
    }
    cout << ">\n";
  }

  return 0;
}
