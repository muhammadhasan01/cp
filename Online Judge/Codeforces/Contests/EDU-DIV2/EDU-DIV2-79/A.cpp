#include <bits/stdc++.h>

using namespace std;

int tc;
int x[3];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> x[0] >> x[1] >> x[2];
    sort(x, x + 3);
    cout << (x[0] + x[1] + 1 >= x[2] ? "Yes" : "No") << '\n';
  }

  return 0;
}
