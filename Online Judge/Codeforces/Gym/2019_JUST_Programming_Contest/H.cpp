#include <bits/stdc++.h>

using namespace std;

int tc, n;
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> s;
    bool flag = true;
    n = s.length();
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == 'z' && s[i + 1] == 'a') continue;
      if (s[i + 1] - s[i] == 1) continue;
      flag = false;
    }
    puts(flag ? "YES" : "NO");
  }

  return 0;
}
