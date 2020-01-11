#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 5;
const ll INF = 1e18;

int n, m, k;
ll w[N];
vector<pair<int, int>> g[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v >> w[i];
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  vector<int> ans;
  set<pair<ll, int>> st;
  vector<ll> dist(n + 3, INF);
  vector<int> vis(m + 3, -1);
  st.insert({0, 1});
  dist[1] = 0;
  int cnt = 0;
  while (!st.empty() && cnt < k) {
    auto z = *st.begin();
    st.erase(st.begin());
    int k = z.second;
    if (vis[k] != -1) {
      cnt++;
      ans.push_back(vis[k]);
    }
    for (auto y : g[k]) {
      int to = y.first;
      int idx = y.second;
      if (dist[to] > dist[k] + w[idx]) {
        st.erase({dist[to], to});
        dist[to] = dist[k] + w[idx];
        vis[to] = idx;
        st.insert({dist[to], to});
      }
    }
  }
  cout << ans.size() << '\n';
  for (auto e : ans) cout << e << " ";
  cout << '\n';

  return 0;
}
