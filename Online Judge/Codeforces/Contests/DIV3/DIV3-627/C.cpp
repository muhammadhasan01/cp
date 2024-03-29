#include <bits/stdc++.h>

using namespace std;

int tc;
string s;
int n;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> s;
    n = s.length();
    int dif = -1;
    int pos = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'R') {
        dif = max(dif, i - pos);
        pos = i;
      }
    }
    dif = max(dif, n - pos);
    cout << dif << '\n';
  }

  return 0;
}