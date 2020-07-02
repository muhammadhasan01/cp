#include <bits/stdc++.h>

using namespace std;

int tc;
int n, x, y;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> x >> y;
    if (x > y) swap(x, y);
    cout << max(1, y - 1 - max(0, n - x - 1) + 1) << " " << min(n, x + y - 1) << '\n';
  }

  return 0;
}