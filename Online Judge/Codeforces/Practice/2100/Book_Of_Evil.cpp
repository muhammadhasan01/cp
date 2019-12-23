#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, m, d;
int dep[N][4];
bool mrk[N];
vector<int> g[N];
int maxp;

void bfs(int u, int type) {
  vector<bool> vis(n + 3);
  queue<pair<int, int>> q;
  q.push({u, 0});
  dep[u][type] = 0;
  int maxl = 0;
  while (!q.empty()) {
    int v = q.front().first;
    int dist = q.front().second;
    q.pop();
    vis[v] = 1;
    dep[v][type] = dist;
    if (mrk[v]) maxp = v;
    for (auto w : g[v]) {
      if (!vis[w]) q.push({w, dist + 1});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> d;
  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    mrk[x] = 1;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  bfs(1, 1);
  bfs(maxp, 2);
  bfs(maxp, 3);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (dep[i][2] <= d && dep[i][3] <= d) ans++;
  }
  cout << ans << '\n';

  return 0;
}
