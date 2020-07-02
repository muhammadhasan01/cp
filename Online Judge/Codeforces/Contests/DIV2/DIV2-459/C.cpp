#include <bits/stdc++.h>

using namespace std;

string s;
int n, ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    int cur = 0;
    int qst = 0;
    for (int j = i; j < n; j++) {
      if (s[j] == '?') qst++;
      else if (s[j] == '(') cur++;
      else if (s[j] == ')') cur--;
      if (cur < 0) break;
      if (qst > cur) qst--, cur++;
      if ((j - i + 1) % 2 == 0 && qst >= cur) ans++;
    }
  }
  cout << ans << '\n';

  return 0;
}
