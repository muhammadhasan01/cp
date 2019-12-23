#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int L = 20;
int n;
long long a[N], d[N];
vector<pair<int, long long>> g[N];
int up[N][L];
int dp[N];

void dfs(int u, int p) {
  up[u][0] = p;
  for (int i = 1; i < L; i++) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  for (auto e : g[u]) {
    int v = e.first;
    long long w = e.second;
    d[v] = d[u] + w;
    dfs(v, u);
  }
}

int go(int u, long long val) {
  int v = u;
  for (int i = L - 1; i >= 0; i--) {
    if (d[u] - d[up[v][i]] <= val) v = up[v][i];
  }
  return up[v][0];
}

void upd(int u) {
  int v = go(u, a[u]);
  dp[v]--;
  dp[u]++;
}

void calc(int u) {
  for (auto e : g[u]) {
    int v = e.first;
    calc(v);
    dp[u] += dp[v];
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
  for (int i = 2; i <= n; i++) {
    int u;
    long long w;
    cin >> u >> w;
    g[u].push_back({i, w});
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) upd(i);
  calc(1);
  for (int i = 1; i <= n; i++) {
    cout << dp[i] - 1 << (i == n ? '\n' : ' ');
  }

  return 0;
}
