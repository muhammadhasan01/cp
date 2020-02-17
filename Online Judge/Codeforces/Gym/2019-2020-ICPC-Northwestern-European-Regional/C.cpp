#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int INF = 1e9;

struct canvas {
  int l, r;
};

int n, p;
int dp[N][3];
int cnt[N];
canvas c[2 * N];
map<int, int> mp;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i].l >> c[i].r;
  }
  cin >> p;
  for (int i = 1; i <= p; i++) {
    int x;
    cin >> x;
    mp[x]++;
    for (int j = 1; j <= n; j++) {
      if (c[j].l <= x && x <= c[j].r) cnt[j]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i] > 2) {
      cout << "impossible" << '\n';
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      dp[i][j] = INF;
    }
  }
  c[0].r = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = cnt[i]; j <= 2; j++) {
      dp[i][j] = j - cnt[i] + dp[i - 1][2];
    }
    int j = cnt[i];
    if (c[i - 1].r == c[i].l && !mp.count(c[i].l) && j < 2) {
      dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][1] + 1);
    }
    dp[i][2] = min(dp[i][2], dp[i][1] + 1);
  }
  vector<int> ans;
  int i = n, j = 2;
  while (i >= 1) {
    if (cnt[i] == 2) {
      i--;
      continue;
    }
    if (cnt[i] == 0) {
      if (j == 2) {
        for (int it = c[i].r - 2; it >= c[i].l + 2; it--) {
          if (!mp.count(it)) {
            mp[it] = 1;
            ans.push_back(it);
            break;
          }
        }
        j--;
      } else if (j == 1) {
        if (c[i - 1].r == c[i].l && !mp.count(c[i].l) && dp[i][j] == dp[i - 1][1] + 1) {
          ans.push_back(c[i].l);
          i--;
        } else {
          for (int it = c[i].r - 2; it >= c[i].l + 2; it--) {
            if (!mp.count(it)) {
              mp[it] = 1;
              ans.push_back(it);
              break;
            }
          }
          i--;
          j++;
        }
      }
      continue;
    }
    if (j == 2) {
      if (c[i - 1].r == c[i].l && !mp.count(c[i].l) && dp[i][j] == dp[i - 1][1] + 1) {
        ans.push_back(c[i].l);
        i--;
        j--;
      } else {
        for (int it = c[i].r - 2; it >= c[i].l + 2; it--) {
          if (!mp.count(it)) {
            mp[it] = 1;
            ans.push_back(it);
            break;
          }
        }
        i--;
      }
    } else if (j == 1) {
      i--;
      j++;
    }
  }
  int len = ans.size();
  reverse(ans.begin(), ans.end());
  cout << len << '\n';
  for (int i = 0; i < len; i++) {
    cout << ans[i] << (i == len - 1 ? '\n' : ' ');
  }

  return 0;
}
