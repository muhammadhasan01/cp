#include <bits/stdc++.h>

using namespace std;

int tc;
int h, mm;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> h >> mm;
    int tim = h * 60 + mm;
    cout << 24 * 60 - tim << '\n';
  }

  return 0;
}
