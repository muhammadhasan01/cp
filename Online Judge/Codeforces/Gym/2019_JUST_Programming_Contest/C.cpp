#include <bits/stdc++.h>

using namespace std;

int tc;
int n, m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    cout << (n & 1 && m & 1 ? 12 : 2) << '\n';
  }

  return 0;
}
