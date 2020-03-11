#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n;
bool mrk[N][N];
vector<int> g[N];
int par[N];
int _u = -1, _v = -1, _w = -1, _h = -1;

void dfs(int u, int p, int h) {
  if (h >= _h) {
    _h = h;
    if (_v == -1) {
      _u = u;
    } else {
      _v = u;
    }
  }
  par[u] = p;
  for (auto v : g[u]) {
    if (mrk[u][v]) continue;
    if (p == v) continue;
    dfs(v, u, h + 1);
  }
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 1, 0);
  _v = _h = 0;
  dfs(_u, _u, 0);
  for (int i = 1; i <= n / 2; i++) {
    cout << "? " << _u << " " << _v << endl;
    cin >> _w;
    int cur = _v;
    while (1) {
      if (cur == par[cur]) break;
      mrk[cur][par[cur]] = 1;
      mrk[par[cur]][cur] = 1;
      cur = par[cur];
    }
    _v = _h = -1;
    dfs(_w, _w, 0);
    _v = _h = 0;
    dfs(_u, _u, 0);
  }
  cout << "! " << _w << endl;

  return 0;
}