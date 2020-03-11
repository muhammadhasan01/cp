#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int n, k, d;
vector<pair<int, int>> g[N];
bool vis[N];
bool ok[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k >> d;
  queue<pair<pair<int, int>, int>> q;
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    if (vis[x]) continue;
    q.push({{x, x}, d});
    vis[x] = 1;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  vector<int> ans;
  while (!q.empty()) {
    pair<pair<int, int>, int> cur = q.front();
    q.pop();
    for (auto& e : g[cur.first.first]) {
      int v = e.first;
      int id = e.second;
      if (v == cur.first.second) continue;
      if (vis[v]) {
        if (ok[id]) continue;
        ok[id] = 1;
        ans.push_back(id);
      } else if (cur.second > 0) {
        vis[v] = 1;
        q.push({{v, cur.first.first}, cur.second - 1});
      }
    }
  }
  cout << ans.size() << '\n';
  for (auto& e : ans) cout << e << " ";
  cout << '\n';

  return 0;
}