#include <bits/stdc++.h>

using namespace std;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s;
  cin >> s;
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    string t;
    cin >> t;
    int k = 0;
    int len = s.size();
    int lenz = t.size();
    if (lenz > len) continue;
    for (int i = 0; i < len; i++) {
      if (s[i] == t[k]) {
        k++;
      }
      if (k == lenz) break;
    }
    if (k == lenz) ans++;
  }
  cout << ans << '\n';

  return 0;
}
