#include <bits/stdc++.h>

using namespace std;

int tc;
string a, b, c;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> a >> b >> c;
    int n = a.length();
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (a[i] == c[i] || b[i] == c[i]) continue;
      flag = false;
    }
    cout << (flag ? "YES" : "NO") << '\n';
  }

  return 0;
}
