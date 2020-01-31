#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
vector<int> g[N];
int sz[N];
double ans[N];

void dfs(int u) {
  sz[u]++;
  int sum = 0;
  for (auto v : g[u]) {
    dfs(v);
    sz[u] += sz[v];
  }
}

void DP(int u) {
  for (auto v : g[u]) {
    ans[v] = 1.0 + ans[u] + (1.0) * (sz[u] - sz[v] - 1) / 2.0;
    DP(v);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    g[x].push_back(i);
  }
  dfs(1);
  ans[1] = 1.0;
  DP(1);
  for (int i = 1; i <= n; i++) {
    cout << fixed << setprecision(9) << ans[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
