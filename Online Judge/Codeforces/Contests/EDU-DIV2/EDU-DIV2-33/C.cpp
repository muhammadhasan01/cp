#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, m;
int par[N];
int dp[N];

int fpar(int x) {
  return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
  int pu = fpar(u);
  int pv = fpar(v);
  if (pu == pv) return;
  if (dp[pu] > dp[pv]) swap(pu, pv);
  par[pv] = pu;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> dp[i];
    par[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    merge(u, v);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (fpar(i) == i) {
      ans += (1LL) * dp[i];
    }
  }
  cout << ans << '\n';

  return 0;
}
