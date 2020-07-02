#include <bits/stdc++.h>

using namespace std;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int ans = 0;
  for (int i = 24; i >= 0; i--) {
    int cur = (1 << i);
    for (auto& e : v) e %= (2 * cur);
    sort(v.begin(), v.end());
    int res = 0;
    for (int i = 1; i < n; i++) {
      int x = v[i];
      auto s = v.begin(), e = v.begin() + i;
      auto it_1 = lower_bound(s, e, 1 * cur - x);
      auto it_2 = lower_bound(s, e, 2 * cur - x);
      auto it_3 = lower_bound(s, e, 3 * cur - x);
      auto it_4 = lower_bound(s, e, 4 * cur - x);
      res += (it_2 - it_1) + (it_4 - it_3);
      res &= 1;
    }
    ans += (res * cur);
  }
  cout << ans << '\n';

  return 0;
}