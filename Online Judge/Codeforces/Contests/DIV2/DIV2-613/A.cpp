#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> s;
  int l = 0, r = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') l++;
    else r++;
  }
  cout << l + r + 1 << '\n';

  return 0;
}
