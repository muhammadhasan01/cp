#include <bits/stdc++.h>

using namespace std;
typedef pair<long long, long long> pll;

const int N = 1e5 + 5;
int n;
vector<int> g[N];
pll ans;
long long v[N];

pll dfs(int u, int p) {
  pll ret = {0LL, 0LL};
  for (auto v : g[u]) {
    if (v == p) continue;
    pll cur = dfs(v, u);
    ret.first = max(ret.first, cur.first);
    ret.second = max(ret.second, cur.second);
  }
  v[u] += ret.second - ret.first;
  if (v[u] > 0) ret.first += v[u];
  else ret.second -= v[u];
  return ret;
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
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  ans = dfs(1, 1);
  cout << ans.first + ans.second << '\n';

  return 0;
}
