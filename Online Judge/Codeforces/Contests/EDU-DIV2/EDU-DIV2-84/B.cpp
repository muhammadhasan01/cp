#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
int n;
vector<int> v[N];
int lenz[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n;
    vector<int> vis(n + 1);
    vector<bool> ok(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> lenz[i];
      v[i].resize(lenz[i] + 1);
      for (int j = 1; j <= lenz[i]; j++) {
        cin >> v[i][j];
      }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= lenz[i]; j++) {
        if (!vis[v[i][j]]) {
          vis[v[i][j]] = 1;
          ok[i] = 1;
          break;
        }
      }
      if (ok[i]) cnt++;
    }
    if (cnt == n) {
      cout << "OPTIMAL" << '\n';
      continue;
    }
    int rem = 0;
    for (int i = 1; i <= n; i++) {
      if (vis[i] == 0) {
        rem = i;
        break;
      }
    }
    for (int i = n; i >= 1; i--) {
      if (!ok[i]) {
        cout << "IMPROVE" << '\n';
        cout << i << " " << rem << '\n';
        break;
      }
    }
  }

  return 0;
}