#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const long long INF = 1e18;

typedef pair<long long, int> pli;

int n, m, src;
vector<pair<int, int>> g[N];
long long w[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v >> w[i];
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  cin >> src;
  priority_queue<pli, vector<pli>, greater<pli>> pq;
  vector<long long> dist(n + 1, INF);
  dist[src] = 0;
  pq.push({dist[src], src});
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    for (auto e : g[u]) {
      int v = e.first;
      int idx = e.second;
      long long weight = w[idx];
      if (dist[v] > weight + dist[u]) {
        dist[v] = weight + dist[u];
        pq.push({dist[v], v});
      }
    }
  }
  long long ans = 0;
  set<int> res;
  vector<long long> dis(n + 1, INF);
  vector<pair<long long, int>> key(n + 1, {INF, -1});
  set<pair<long long, int>> q;
  dis[src] = 0;
  q.insert({dis[src], src});
  while (!q.empty()) {
    int u = (q.begin() -> second);
    q.erase(q.begin());
    for (auto e : g[u]) {
      int v = e.first;
      int idx = e.second;
      long long weight = w[idx];
      if (dist[v] == weight + dis[u]) {
        q.erase({dis[v], v});
        dis[v] = dist[v];
        q.insert({dis[v], v});
        if (key[v].first > weight) {
          res.erase(key[v].second);
          res.insert(idx);
          key[v] = {weight, idx};
        }
      }
     }
  }
  for (auto e : res) ans += w[e];
  cout << ans << '\n';
  for (auto e : res) cout << e << " ";
  cout << '\n';

  return 0;
}
