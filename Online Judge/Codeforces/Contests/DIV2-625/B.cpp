#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
long long b[N];
int par[N];
long long dp[N];
map<int, int> mp;

int fpar(int x) {
  return (x == par[x] ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
  int pu = fpar(u);
  int pv = fpar(v);
  if (pu == pv) return;
  if (dp[pu] < dp[pv]) swap(pu, pv);
  dp[pu] += dp[pv];
  par[pv] = pu;
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    par[i] = i;
    dp[i] = b[i];
  }
  for (int i = 1; i <= n; i++) {
    int cur = b[i] - i;
    if (mp.count(cur) > 0) {
      merge(mp[cur], i);
    } else {
      mp[cur] = i;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i == fpar(i)) {
      ans = max(ans, dp[i]);
    }
  }
  cout << ans << '\n';

  return 0;
}