#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int n, q;
int depth[N], tin[N], tout[N], tim;
vector<int> g[N];
vector<int> dis[N];
vector<long long> cnt[N];
int dist;
long long ans[N];

void dfs(int u, int p, int h) {
  tin[u] = ++tim;
  dis[h].push_back(u);
  dist = max(dist, h);
  depth[u] = h;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u, h + 1);
  }
  tout[u] = ++tim;
}

void DP(int u, int p) {
  for (auto v : g[u]) {
    if (v == p) continue;
    ans[v] += ans[u];
    DP(v, u);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 1, 0);
  for (int i = 0; i <= dist; i++) {
    cnt[i].assign(dis[i].size() + 1, 0);
  }
  cin >> q;
  while (q--) {
    int v, d;
    long long x;
    cin >> v >> d >> x;
    ans[v] += x;
    d = depth[v] + d + 1;
    if (d > dist) continue;
    int l1 = 0, r1 = dis[d].size() - 1, pos1 = 1e9;
    while (l1 <= r1) {
      int mid = (l1 + r1) >> 1;
      if (tin[dis[d][mid]] >= tin[v]) {
        r1 = mid - 1;
        pos1 = mid;
      } else {
        l1 = mid + 1;
      }
    }
    int l2 = 0, r2 = dis[d].size() - 1, pos2 = -1;
    while (l2 <= r2) {
      int mid = (l2 + r2) >> 1;
      if (tout[dis[d][mid]] <= tout[v]) {
        l2 = mid + 1;
        pos2 = mid;
      } else {
        r2 = mid - 1;
      }
    }
    if (pos1 > pos2) continue;
    cnt[d][pos1] += x;
    cnt[d][pos2 + 1] -= x;
  }
  for (int i = 0; i <= dist; i++) {
    for (int j = 0; j < (int) dis[i].size(); j++) {
      if (j) cnt[i][j] += cnt[i][j - 1];
      ans[dis[i][j]] -= cnt[i][j];
    }
  }
  DP(1, 1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
