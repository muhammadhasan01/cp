#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc;
string s, t;
int loc[30];
int oc[30][N];

bool can(int x, int y) {
  int now = -1;
  for (int i = x; i <= y; i++) {
    int al = (t[i] - 'a');
    int l = 1, r = loc[al], pos = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (oc[al][mid] > now) {
        r = mid - 1;
        pos = oc[al][mid];
      } else {
        l = mid + 1;
      }
    }
    if (pos == -1) return false;
    now = pos;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> s >> t;
    for (int i = 0; i < 26; i++) loc[i] = 0;
    for (int i = 0; i < (int) s.size(); i++) {
      int al = s[i] - 'a';
      oc[al][++loc[al]] = i;
    }
    int n = t.size();
    int i = 0;
    bool flag = true;
    int ans = 0;
    while (i < n) {
      int l = i, r = n - 1, pos = -1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(i, mid)) {
          l = mid + 1;
          pos = mid;
        } else {
          r = mid - 1;
        }
      }
      if (pos == -1) {
        flag = false;
        break;
      }
      ans++;
      i = pos + 1;
    }
    if (!flag) {
      cout << -1 << '\n';
      continue;
    }
    cout << ans << '\n';
  }

  return 0;
}
