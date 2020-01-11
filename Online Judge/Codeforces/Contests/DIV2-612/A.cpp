#include <bits/stdc++.h>

using namespace std;

int tc;
int k;
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> k >> s;
    int ans = 0;
    for (int i = 0; i < k; i++) {
      if (s[i] == 'A') {
        int cur = 0;
        for (int j = i + 1; j < k; j++) {
          if (s[j] == 'P') cur++;
          else {
            break;
          }
        }
        ans = max(ans, cur);
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
