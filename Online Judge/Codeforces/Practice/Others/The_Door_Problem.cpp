#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m;
bool a[N];
vector<int> c[N];
vector<pair<int, bool>> g[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    int sz;
    cin >> sz;
    for (int j = 1; j <= sz; j++) {
      int x;
      cin >> x;
      c[x].push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    int u = c[i][0];
    int v = c[i][1];
    g[u].push_back({v, a[i]});
    g[v].push_back({u, a[i]});
  }
  vector<int> col(m + 1, -1);
  vector<bool> vis(m + 1, false);
  for (int i = 1; i <= m; i++) {
    if (!vis[i]) {
      queue<int> q;
      q.push(i);
      vis[i] = true;
      col[i] = 0;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        bool col_u = col[u];
        for (auto e : g[u]) {
          int v = e.first;
          bool k = e.second;
          bool req = (k ? col_u : !(col_u));
          if (vis[v] && col[v] != req) {
            cout << "NO" << '\n';
            return 0;
          }
          if (!vis[v]) {
            col[v] = req;
            vis[v] = 1;
            q.push(v);
          }
        }
      }
    }
  }
  cout << "YES" << '\n';

  return 0;
}
