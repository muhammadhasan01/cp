#include <bits/stdc++.h>

using namespace std;



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int h;
  vector<int> v(4);
  int sum = 0;
  for (int i = 0; i < 4; i++) {
    cin >> v[i];
    sum += v[i];
  }
  cin >> h;
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    ans = max(ans, sum - v[i]);
  }
  cout << (ans >= h ? "WAW" : "AWW") << '\n';

  return 0;
}
