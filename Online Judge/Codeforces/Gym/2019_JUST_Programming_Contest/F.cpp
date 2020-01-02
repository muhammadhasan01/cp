#include <bits/stdc++.h>

using namespace std;



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    s[0] = toupper(s[0]);
    int cnt = 0;
    for (auto e : s) {
      if ('A' <= e && e <= 'Z') cnt++;
    }
    puts(cnt <= 7 ? "YES" : "NO");e
  }

  return 0;
}
