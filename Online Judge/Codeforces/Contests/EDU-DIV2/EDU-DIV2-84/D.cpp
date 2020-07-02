#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc;
int n;
int p[N], c[N];
int ans;

void check(vector<int>& v, int h) {
  for (int i = 0; i < h; i++) {
    bool flag = true;
    for (int j = i; j < (int) v.size(); j += h) {
      if (v[i] != v[j]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      ans = min(ans, h);
      return;
    }
  }
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n;
    ans = n;
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> c[i];
    }
    vector<vector<int>> v(n + 1);
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        v[i].push_back(c[i]);
        vis[i] = 1;
        int cur = p[i];
        while (cur != i) {
          v[i].push_back(c[cur]);
          vis[cur] = 1;
          cur = p[cur];
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      int len = v[i].size();
      if (len == 0) continue;
      for (int j = 0; j < len; j++) {
        v[i].push_back(v[i][j]);
      }
      for (int k = 1; k * k <= len; k++) {
        if (len % k == 0) {
          check(v[i], k);
          if (k * k != len) check(v[i], len / k);
        }
      }
    }
    cout << ans << '\n';
  }

  return 0;
}