#include <bits/stdc++.h>

using namespace std;

int tc;
int n;
long long a, b, p;
string s;

bool can(int x) {
  long long res = 0;
  char last = '#';
  for (int i = x; i < n - 1; i++) {
    if (last != s[i]) {
      last = s[i];
      res += (s[i] == 'A' ? a : b);
    }
    if (res > p) return false;
  }
  return true;
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> a >> b >> p >> s;
    n = s.length();
    int l = 0, r = n - 1;
    int ans = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (can(mid)) {
        r = mid - 1;
        ans = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << ans + 1 << '\n';
  }

  return 0;
}