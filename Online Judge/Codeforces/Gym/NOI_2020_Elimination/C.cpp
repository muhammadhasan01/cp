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
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n - 1; i++) {
      string k = s.substr(i, 2);
      if (k == "TJ") {
        a++;
      } else if (k == "si") {
        b++;
      } else if (k == "lo" && i + 2 < n && s[i + 2] == 'g') {
        c++;
      }
    }
    cout << a << " " << b << " " << c << '\n';
  }

  return 0;
}
