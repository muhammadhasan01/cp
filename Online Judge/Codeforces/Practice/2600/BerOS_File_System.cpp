#include <bits/stdc++.h>

using namespace std;

string s;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  while (s.back() == '/') s.pop_back();
  if (s.empty()) {
    cout << '/' << '\n';
    return 0;
  }
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (i > 0 && s[i] == '/' && s[i - 1] == '/') continue;
    cout << s[i];
  }
  cout << '\n';

  return 0;
}