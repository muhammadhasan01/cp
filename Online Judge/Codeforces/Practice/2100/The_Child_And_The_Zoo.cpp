#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m;
pair<long long, int> a[N];
vector<int> g[N];
bool vis[N];
int par[N];
long long sz[N];
long long res = 0;

int fpar(int x) {
  return (par[x] == x ? x : par[x] = fpar(par[x]));
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
    par[i] = i, sz[i] = 1;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  sort(a + 1, a + 1 + n, greater<pair<int, int>>());
  for (int i = 1; i <= n; i++) {
    int u = a[i].second;
    long long val = a[i].first;
    int pu = fpar(u);
    for (auto v : g[u]) {
      if (!vis[v]) continue;
      int pv = fpar(v);
      if (pu == pv) continue;
      par[pv] = pu;
      res += (2LL) * val * sz[pv] * sz[pu];
      sz[pu] += sz[pv];
    }
    vis[u] = 1;
  }
  cout << fixed << setprecision(12);
  cout << (long double) res / ((long double) n * (n - 1)) << '\n';

  return 0;
}