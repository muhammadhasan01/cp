#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
vector<int> g[N];
int dp[N][3];
int ans[N];
vector<int> divisor, cnt;

void dfs1(int u, int p) {
  for (auto v : g[u]) {
    if (v == p) continue;
    ans[v] = __gcd(a[v], ans[u]);
    dfs1(v, u);
  }
}

void dfs2(int u, int p, int dist) {
  for (int i = 0; i < (int) divisor.size(); i++) {
    cnt[i] += (a[u] % divisor[i] == 0);
    if (cnt[i] >= dist) {
      ans[u] = max(ans[u], divisor[i]);
    }
  }
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs2(v, u, dist + 1);
  }
  for (int i = 0; i < (int) divisor.size(); i++) {
    cnt[i] -= (a[u] % divisor[i] == 0);
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
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ans[1] = 0;
  dfs1(1, 1);
  for (int i = 1; i * i <= a[1]; i++) {
    if (a[1] % i == 0) {
      divisor.push_back(i);
      if (i * i != a[1]) divisor.push_back(a[1] / i);
    }
  }
  cnt.resize((int) divisor.size());
  dfs2(1, 1, 0);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
