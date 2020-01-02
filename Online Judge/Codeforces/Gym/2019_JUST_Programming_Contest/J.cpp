#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int tc;
int n, m, ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    map<int, int> mp[2];
    ans = 0;
    for (int i = 1; i <= n; i++) {
      int now = i & 1;
      int bfr = !(now);
      mp[now].clear();
      for (int j = 1; j <= m; j++) {
        int x;
        cin >> x;
        mp[now][x]++;
      }
      if (i >= 2) {
        int now = i & 1;
        int bfr = !(now);
        for (auto e : mp[now]) {
          ans += min(e.second, mp[bfr][e.first]);
        }
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
