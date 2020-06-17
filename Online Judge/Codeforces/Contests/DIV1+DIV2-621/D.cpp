#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
 
int n, m, k;
vector<int> g[N];
int a[N];
bool vis[N];
int dist[N][2];
int suf[N];
pair<int, int> p[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  queue<pair<int, int>> q;
  dist[1][0] = 0;
  vis[1] = 1;
  q.push({1, 0});
  while (!q.empty()) {
    int u = q.front().first;
    int d = q.front().second;
    q.pop();
    for (auto v : g[u]) {
      if (vis[v]) continue;
      vis[v] = 1;
      dist[v][0] = d + 1;
      q.push({v, d + 1});
    }
  }
  memset(vis, 0, sizeof(vis));
  q.push({n, 0});
  vis[n] = 1;
  dist[n][1] = 0;
  while (!q.empty()) {
    int u = q.front().first;
    int d = q.front().second;
    q.pop();
    for (auto v : g[u]) {
      if (vis[v]) continue;
      vis[v] = 1;
      dist[v][1] = d + 1;
      q.push({v, d + 1});
    }
  }
  for (int i = 1; i <= k; i++) {
    p[i] = {dist[a[i]][0], dist[a[i]][1]};
  }
  sort(p + 1, p + 1 + k, [&](auto x, auto y) {
    return (x.first - x.second < y.first - y.second);
  });
  for (int i = k; i >= 1; i--) {
    suf[i] = max(suf[i + 1], p[i].second);
  }
  int ans = 0;
  for (int i = 1; i <= k - 1; i++) {
    ans = max(ans, p[i].first + suf[i + 1] + 1);
  }
  ans = min(ans, dist[n][0]);
  cout << ans << '\n';
 
  return 0;
}