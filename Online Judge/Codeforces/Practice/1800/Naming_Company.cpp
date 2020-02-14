#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.rbegin(), t.rend());
  int n = s.length();
  if (n == 1) {
    cout << s << '\n';
    return 0;
  }
  string ans(n, '#');
  vector<bool> vis(n + 1);
  int turn = 1;
  int ifs = 0, ibs = n / 2 - (n % 2 == 0);
  int ift = 0, ibt = (n % 2 == 0 ? ibs : ibs - 1);
  for (int i = n, j = 0, k = n - 1; i >= 1; i--) {
    char x = s[ifs];
    char y = t[ift];
    if (x >= y) {
      ans[k--] = (turn ? s[ibs--] : t[ibt--]);
    } else {
      ans[j++] = (turn ? s[ifs++] : t[ift++]);
    }
    turn = 1 - turn;
  }
  cout << ans << "\n";

  return 0;
}
