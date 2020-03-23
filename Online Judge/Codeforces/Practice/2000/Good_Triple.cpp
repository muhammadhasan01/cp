#include <bits/stdc++.h>

using namespace std;

string s;
int n;
long long ans;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  n = s.length();
  int p = n + 1;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 1; i + 2 * j < n; ++j) {
      if (s[i] == s[i + j] && s[i + j] == s[i + 2 * j]) {
        p = min(p, i + 2 * j);
        break;
      }
    }
    ans += (1LL) * max(0, n - p);
  }
  cout << ans << '\n';

  return 0;
}