#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

int n, m;
vector<pair<int, long long>> g[N];
vector<long long> v[N];
vector<long long> dp[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    long long w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  for (int i = 1; i <= n; i++) {
    int sz;
    cin >> sz;
    v[i].resize(sz);
    for (int j = 0; j < sz; j++) {
      cin >> v[i][j];
    }
    dp[i].resize(sz);
    for (int j = sz - 1; j >= 0; j--) {
      if (j == sz - 1) {
        dp[i][j] = v[i][j] + 1;
      } else if (v[i][j] == v[i][j + 1] - 1) {
        dp[i][j] = dp[i][j + 1];
      } else {
        dp[i][j] = v[i][j] + 1;
      }
    }
  }
  vector<long long> dist(n + 3, INF);
  set<pair<long long, int>> q;
  dist[1] = 0LL;
  auto iter = lower_bound(v[1].begin(), v[1].end(), dist[1]);
  if (iter != v[1].end() && *iter == dist[1]) {
    dist[1] = dp[1][(int) (iter - v[1].begin())];
  }
  q.insert({dist[1], 1});
  while (!q.empty()) {
    auto cur = *q.begin();
    q.erase(q.begin());
    int u = cur.second;
    for (auto e : g[u]) {
      int to = e.first;
      long long w = e.second;
      long long resdist = dist[u] + w;
      if (to != n) {
        auto it = lower_bound(v[to].begin(), v[to].end(), resdist);
        if (it != v[to].end() && *it == resdist) {
          resdist = dp[to][(int) (it - v[to].begin())];
        }
      }
      if (dist[to] > resdist) {
        q.erase({dist[to], to});
        dist[to] = resdist;
        q.insert({dist[to], to});
      }
    }
  }
  if (dist[n] == INF) dist[n] = -1;
  cout << dist[n] << '\n';

  return 0;
}
