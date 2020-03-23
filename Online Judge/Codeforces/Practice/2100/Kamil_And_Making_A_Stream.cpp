#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> pll;

const int N = 1e5 + 5;
const long long M = 1e9 + 7;

int n;
vector<int> g[N];
long long x[N];
long long ans;

void dfs(int u, int p, vector<pll> vtr) {
  vector<pll> old = vtr;
  vtr.clear();
  for (auto& e : old) {
    e.first = __gcd(e.first, x[u]);
  }
  old.push_back({x[u], 1LL});
  int len = old.size();
  for (int i = 0; i < len; i++) {
    int j = i;
    long long cnt = 0;
    while (j < len && old[j].first == old[i].first) {
      cnt += old[j].second;
      j++;
    }
    vtr.push_back({old[i].first, cnt});
    i = j - 1;
  }
  old.clear();
  for (auto& e : vtr) {
    ans = (ans + e.first * e.second) % M;
  }
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u, vtr);
  }
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 1, {});
  cout << ans << '\n';

  return 0;
}