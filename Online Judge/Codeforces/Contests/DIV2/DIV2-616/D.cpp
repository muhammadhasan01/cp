#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

string s;
int tc;
int pre[N][30];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  s = "#" + s + "#";
  int n = s.length() - 1;
  for (int i = 1; i <= n; i++) {
    for (int t = 0; t < 26; t++) pre[i][t] = pre[i - 1][t];
    pre[i][s[i] - 'a']++;
  }
  cin >> tc;
  while (tc--) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << "Yes" << '\n';
      continue;
    }
    if (s[l] == s[r]) {
      int al = s[l] - 'a';
      int cnt = 0;
      for (int j = 0; j < 26; j++) {
        if (pre[r][j] - pre[l - 1][j] > 0) cnt++;
      }
      if (pre[r][al] - pre[l - 1][al] == r - l + 1) {
        cout << "No" << '\n';
      } else {
        cout << (cnt >= 3 ? "Yes" : "No") << '\n';
      }
    } else {
      cout << "Yes" << '\n';
    }
  }

  return 0;
}
