#include <bits/stdc++.h>

using namespace std;

const int N = 205;

int tc;
string s;
int n;
int x[N];
string pat = "abcdefghijklmnopqrstuvwxyz";

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; i++) {
      x[i] = (s[i] - 'a');
    }
    if (n == 1) {
      cout << "YES" << '\n';
      cout << pat << '\n';
      continue;
    }
    set<int> s[30];
    for (int i = 0; i < n; i++) {
      if (i + 1 < n) {
        s[x[i]].insert(x[i + 1]);
      }
      if (i - 1 >= 0) {
        s[x[i]].insert(x[i - 1]);
      }
    }
    bool flag = false;
    vector<int> cnt;
    for (int i = 0; i < 26; i++) {
      int len = s[i].size();
      if (len > 2) {
        flag = true;
        break;
      }
      if (len == 1) cnt.push_back(i);
    }
    if (flag || (int) cnt.size() != 2) {
      cout << "NO" << '\n';
      continue;
    }
    vector<bool> vis(30);
    int now = cnt[1];
    cout << "YES" << '\n';
    while (1) {
      cout << pat[now];
      vis[now] = 1;
      bool br = false;
      for (auto e : s[now]) {
        if (!vis[e]) {
          now = e;
          br = true;
        }
      }
      if (!br) break;
    }
    for (int i = 0; i < 26; i++) {
      if (!vis[i]) cout << pat[i];
    }
    cout << '\n';
  }

  return 0;
}
