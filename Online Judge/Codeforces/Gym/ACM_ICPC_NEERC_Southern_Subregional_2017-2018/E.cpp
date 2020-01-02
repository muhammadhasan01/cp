#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int M = 1e3 + 5;
int n, m;
string s, a;
vector<vector<int>> v;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> s;
  vector<int> cnt(30);
  for (auto e : s) {
    if (e != '*') cnt[e - 'a'] = true;
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a;
    bool valid = true;
    for (int j = 0; j < n; j++) {
      if (s[j] == '*' && cnt[a[j] - 'a'] > 0) {
        valid = false;
        break;
      } else if (s[j] != '*' && s[j] != a[j]) {
        valid = false;
        break;
      }
    }
    if (valid) {
      vector<int> cur(30);
      for (int j = 0; j < n; j++) {
        if (s[j] == '*') cur[a[j] - 'a'] = true;
      }
      v.push_back(cur);
    }
  }
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    bool flag  = true;
    for (auto e : v) {
      if (!e[i]) {
        flag = false;
        break;
      }
    }
    if (flag) ans++;
  }
  cout << ans << '\n';

  return 0;
}
