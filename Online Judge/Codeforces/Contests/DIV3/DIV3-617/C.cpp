#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int INF = 2e9;

int tc;
int n;
char a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n;
    int x = 0, y = 0;
    map<pair<int, int>, int> mp;
    mp[{0, 0}] = 0;
    int ans = INF;
    int ans_x = 0, ans_y = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] == 'L') {
        x++;
      } else if (a[i] == 'R') {
        x--;
      } else if (a[i] == 'U') {
        y++;
      } else if (a[i] == 'D') {
        y--;
      }
      pair<int, int> cur = {x, y};
      if (!mp.count(cur)) {
        mp[cur] = i;
      } else {
        int dif = i - mp[cur];
        if (dif < ans) {
          ans = dif;
          ans_x = mp[cur] + 1;
          ans_y = i;
        }
        mp[cur] = i;
      }
    }
    if (ans == INF) {
      cout << -1 << '\n';
    } else {
      cout << ans_x << " " << ans_y << '\n';
    }
  }

  return 0;
}
