#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n, m;
string s[N];
bool pal[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    bool flag = true;
    for (int j = 0; j < m; j++) {
      if (s[i][j] != s[i][m - j - 1]) {
        flag = false;
        break;
      }
    }
    pal[i] = flag;
  }
  vector<bool> vis(n + 1);
  vector<pair<int, int>> v;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      string cur = s[j];
      reverse(cur.begin(), cur.end());
      if (s[i] == cur) {
        vis[i] = vis[j] = 1;
        v.push_back({i, j});
        break;
      }
    }
  }
  string ans = "";
  for (auto e : v) {
    ans += s[e.first];
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0 && pal[i]) {
      ans += s[i];
      break;
    }
  }
  reverse(v.begin(), v.end());
  for (auto e : v) {
    ans += s[e.second];
  }
  cout << ans.size() << '\n';
  cout << ans << "\n";

  return 0;
}
