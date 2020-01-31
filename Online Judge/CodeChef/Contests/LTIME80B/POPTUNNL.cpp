#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int INF = 2e9;

int tc;
int n, k;
char a[N][N];
vector<int> g[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
      }
      g[i].clear();
    }
    if (a[1][1] == '0') {
      cout << -1 << '\n';
      continue;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = max(1, i - k); j <= min(n, i + k); j++) {
        if (a[i][j] == '1') {
          g[i].push_back(j);
        }
      }
    }
    set<pair<int, int>> q;
    vector<bool> vis(n + 5);
    vector<int> dist(n + 5, INF);
    dist[1] = 0;
    q.insert({0, 1});
    vis[1] = 1;
    while (!q.empty()) {
      auto z = q.begin();
      int u = z -> second;
      q.erase(q.begin());
      for (auto v : g[u]) {
        if (dist[v] > dist[u] + 1) {
          q.erase({dist[v], v});
          dist[v] = dist[u] + 1;
          q.insert({dist[v], v});
        }
      }
    }
    if (dist[n] == INF) dist[n] = -1;
    cout << dist[n] << '\n';
  }

  return 0;
}
