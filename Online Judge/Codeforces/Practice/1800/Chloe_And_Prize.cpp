#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long INF = 2e18;
int n;
long long a[N], dp[N];
vector<int> g[N];
long long ans = -INF;

void dfs(int u, int p) {
  dp[u] += a[u];
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    dp[u] += dp[v];
  }
}

void DP(int u, int p) {
  vector<long long> pq;
  for (auto v : g[u]) {
    if (v == p) continue;
    DP(v, u);
    dp[u] = max(dp[u], dp[v]);
    pq.push_back(dp[v]);
    if ((int) pq.size() > 2) {
      sort(pq.begin(), pq.end(), greater<long long>());
      pq.pop_back();
    }
  }
  if ((int) pq.size() == 2) {
    ans = max(ans, pq[0] + pq[1]);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 1);
  DP(1, 1);
  if (ans == -INF) {
    cout << "Impossible" << '\n';
  } else {
    cout << ans << '\n';
  }

  return 0;
}
