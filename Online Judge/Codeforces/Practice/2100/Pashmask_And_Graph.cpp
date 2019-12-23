#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int M = 1e5 + 5;
int n, m;
vector<pair<int, int>> w[M];
int dp[N], tmp[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, d;
    cin >> u >> v >> d;
    w[d].push_back({u, v});
  }
  for (int i = 1; i < M; i++) {
    for (auto e : w[i]) {
      tmp[e.second] = 0;
    }
    for (auto e : w[i]) {
      tmp[e.second] = max(tmp[e.second], dp[e.first] + 1);
    }
    for (auto e : w[i]) {
      dp[e.second] = max(dp[e.second], tmp[e.second]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';

  return 0;
}
