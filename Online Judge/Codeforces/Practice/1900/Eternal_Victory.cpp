#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n;
vector<pair<int, int>> g[N];
long long ans = 0;
long long maks = 0;

void dfs(int u, int p, long long dist) {
  maks = max(maks, dist);
  for (auto e : g[u]) {
    int v = e.first;
    if (v == p) continue;
    long long w = e.second;
    dfs(v, u, dist + w);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
    ans += (1LL) * w;
  }
  dfs(1, 1, 0LL);
  cout << 2LL * ans - maks << '\n';

  return 0;
}
