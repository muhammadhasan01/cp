#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s;
  cin >> s;
  int n = s.size();
  int i = 0, j = n - 1;
  string ans;
  while (j - i >= 3) {
    if (s[i] == s[j]) {
      ans.push_back(s[i]);
      i++, j--;
    } else if (s[i] == s[j - 1]) {
      ans.push_back(s[i]);
      i++, j -= 2;
    } else {
      ans.push_back(s[i + 1]);
      if (s[i + 1] == s[j]) {
        --j;
      } else {
        j -= 2;
      }
      i += 2;
    }
  }
  string rans = ans;
  if (j >= i) ans.push_back(s[i]);
  reverse(rans.begin(), rans.end());
  cout << ans << rans << '\n';

  return 0;
}
