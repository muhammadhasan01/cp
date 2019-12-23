#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = 1e9 + 7;
int n;
bool c[N];
long long dp[N][2];
vector<int> g[N];
long long ans = 1;

void dfs(int u, int p) {
  long long zero, one;
  dp[u][0] = 1 - c[u];
  dp[u][1] = c[u];
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    zero = dp[u][0];
    one = dp[u][1];
    dp[u][0] = dp[u][1] = 0;

    dp[u][0] = (zero * dp[v][0]) % M;
    dp[u][1] = (one * dp[v][0] + zero * dp[v][1]) % M;

    dp[u][0] += (zero * dp[v][1]) % M;
    dp[u][1] += (one * dp[v][1]) % M;

  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    g[i].push_back(x);
    g[x].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  dfs(0, 0);
  cout << (dp[0][1] % M + M) % M << '\n';

  return 0;
}
