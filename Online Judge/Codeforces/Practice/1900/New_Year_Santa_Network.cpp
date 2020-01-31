#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, q;
vector<pair<int, int>> g[N];
int ord[N];
long long w[N];
long long sz[N];
long long sum = 0;

void dfs(int u, int p) {
  sz[u]++;
  for (auto e : g[u]) {
    int v = e.first;
    int idx = e.second;
    if (v == p) continue;
    dfs(v, u);
    sum += (sz[v] * (n - sz[v]) * w[idx]);
    ord[idx] = v;
    sz[u] += sz[v];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v >> w[i];
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  dfs(1, 1);
  long double dn = n;
  cin >> q;
  while (q--) {
    int i;
    long long wgt;
    cin >> i >> wgt;
    long long dif = w[i] - wgt;
    w[i] = wgt;
    sum -= (sz[ord[i]] * (n - sz[ord[i]]) * dif);
    long double cur = sum;
    cur = (6.0 * cur) / (dn * (dn - 1));
    cout << fixed << setprecision(12) << cur << '\n';
  }

  return 0;
}
