#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

int n, m, k;
vector<pair<int, int>> g[N];
bool train[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  set<pair<long long, int>> q;
  vector<long long> dist(n + 1, INF);
  dist[1] = 0;
  q.insert({dist[1], 1});
  for (int i = 1; i <= k; i++) {
    int x, s;
    cin >> x >> s;
    if (dist[x] > s) {
      q.erase({dist[x], x});
      dist[x] = s;
      q.insert({dist[x], x});
    }
    train[x] = 1;
  }
  while (!q.empty()) {
    auto z = *q.begin();
    q.erase(q.begin());
    int u = z.second;
    for (auto e : g[u]) {
      int v = e.first;
      long long w = e.second;
      if (train[v] && dist[v] >= dist[u] + w) train[v] = 0;
      if (dist[v] > dist[u] + w) {
        q.erase({dist[v], v});
        dist[v] = dist[u] + w;
        q.insert({dist[v], v});
      }
    }
  }
  int ans = k;
  for (int i = 1; i <= n; i++) {
    if (train[i]) ans--;
  }
  cout << ans << '\n';

  return 0;
}