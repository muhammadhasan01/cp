#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
vector<int> g[N];
vector<pair<int, int>> dp[N];
int ans;

void dfs(int u, int p) {
  vector<pair<int, int>> res;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    for (auto e : dp[v]) res.push_back(e);
  }
  sort(res.begin(), res.end());
  int len = res.size();
  for (int i = 0; i < len; i++) {
    int j = i - 1;
    int mx1 = 0, mx2 = 0;
    while (j + 1 < len && res[i].first == res[j + 1].first) {
      j++;
      if (res[j].second >= mx1) {
        mx2 = mx1;
        mx1 = res[j].second;
      } else if (res[j].second > mx2) {
        mx2 = res[j].second;
      }
    }
    if (a[u] % res[i].first == 0) {
      ans = max(ans, mx1 + mx2 + 1);
      dp[u].push_back({res[i].first, mx1 + 1});
      while (a[u] % res[i].first == 0) a[u] /= res[i].first;
    } 
    i = j;
  }
  for (int i = 2; i * i <= a[u]; i++) {
    if (a[u] % i == 0) {
      dp[u].push_back({i, 1});
      ans = max(ans, 1);
      while (a[u] % i == 0) a[u] /= i;
    }
  }
  if (a[u] > 1) {
    dp[u].push_back({a[u], 1});
    ans = max(ans, 1);
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
  cout << ans << '\n';

  return 0;
}