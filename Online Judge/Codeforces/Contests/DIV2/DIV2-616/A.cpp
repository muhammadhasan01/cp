#include <bits/stdc++.h>

using namespace std;

int tc;
int n;
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> s;
    int k = 0;
    for (int i = 0; i < n; i++) {
      int now = (s[i] - '0');
      if (now & 1) {
        k ^= 1;
      }
    }
    int last = (s[n - 1] - '0');
    if (k == 0 && last & 1) {
      cout << s << '\n';
      continue;
    } else if (k == 0 && last % 2 == 0) {
      while (!s.empty() && (s.back() - '0') % 2 == 0) {
        s.pop_back();
      }
      if (!s.empty()) {
        cout << s << '\n';
      } else {
        cout << -1 << '\n';
      }
      continue;
    } else if (k != 0) {
      int pos = -1;
      for (int i = n - 1; i >= 0; i--) {
        int now = (s[i] - '0');
        if (now & 1) {
          pos = i;
          break;
        }
      }
      s.erase(s.begin() + pos);
      while (!s.empty() && (s.back() - '0') % 2 == 0) {
        s.pop_back();
      }
      if (!s.empty()) {
        cout << s << '\n';
      } else {
        cout << -1 << '\n';
      }
    }

  }

  return 0;
}
