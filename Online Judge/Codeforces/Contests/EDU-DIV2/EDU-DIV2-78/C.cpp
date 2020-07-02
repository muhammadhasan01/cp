#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int tc;
int n;
int a[N], pre[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
      cin >> a[i];
    }
    map<int, int> mp;
    mp[0] = 0;
    vector<int> c(2);
    for (int i = 1; i <= n; i++) {
      c[a[i] & 1]++;
      mp[c[0] - c[1]] = i;
    }
    map<int, int> pm;
    pm[0] = 2 * n + 1;
    vector<int> d(2);
    for (int i = 2 * n; i >= n + 1; i--) {
      d[a[i] & 1]++;
      pm[d[1] - d[0]] = i;
    }
    int ans = 2 * n;
    for (int i = 0; i <= n; i++) {
      if (mp.count(i) > 0 && pm.count(i) > 0) {
        ans = min(ans, pm[i] - mp[i] - 1);
      }
      if (mp.count(-i) > 0 && pm.count(-i) > 0) {
        ans = min(ans, pm[-i] - mp[-i] - 1);
      }
    }
    cout << ans << '\n';
  }


  return 0;
}
