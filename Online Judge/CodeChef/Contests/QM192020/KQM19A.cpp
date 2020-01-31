#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 5;

int n, t;
vector<int> g[N];
int deg[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> t;
  for (int i = 1; i <= t; i++) {
    int u = 0;
    cin >> u;
    string s;
    cin.ignore();
    getline(cin, s);
    s += " ";
    int cur = 0;
    for (int i = 0; i < (int) s.size(); i++) {
      if (s[i] == ' ') {
        g[u].push_back(cur);
        deg[cur]++;
        cur = 0;
      } else {
        cur = 10 * cur + (s[i] - '0');
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if ((int) g[i].size() == 0 && deg[i] == 1) ans++;
  }
  cout << ans << '\n';

  return 0;
}
