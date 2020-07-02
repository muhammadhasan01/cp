#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int n;
vector<int> pos;
vector<int> g[N];
pair<int, int> ans[N];

void dfs(int u, int p) {
  for (auto v : g[u]) {
    if (v == p) continue;
    pos.push_back(v);
  }
  pos.push_back(u);
  reverse(g[u].begin(), g[u].end());
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
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
  pos.push_back(1);
  dfs(1, 0);

  for (int i = 0; i < 2 * n; i++) {
    if (ans[pos[i]].first == 0) {
      ans[pos[i]].first = i + 1;
    } else {
      ans[pos[i]].second = i + 1;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i].first << " " << ans[i].second << '\n';
  }

  return 0;
}
