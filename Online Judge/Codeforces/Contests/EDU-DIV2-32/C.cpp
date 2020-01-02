#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
string s;
int n;
int pre[N][30];

bool can(int x) {
  for (int i = 0; i < 26; i++) {
    bool flag = true;
    for (int j = 1; j <= n - x + 1; j++) {
      if (pre[j + x - 1][i] - pre[j - 1][i] == 0) {
        flag = false;
        break;
      }
    }
    if (flag) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  n = s.length();
  s = '#' + s + '#';
  for (int i = 1; i <= n; i++) {
    for (int t = 0; t < 26; t++) {
      pre[i][t] = pre[i - 1][t];
    }
    pre[i][s[i] - 'a']++;
  }
  int l = 1, r = n, ans = n;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (can(mid)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';

  return 0;
}
