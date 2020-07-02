#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n, m;
int b[N], ev[2 * N];
int par[N], sz[N];

int fpar(int x) {
  return (par[x] == x ? x : par[x] = fpar(par[x]));
}

bool merge(int u, int v) {
  int pu = fpar(u);
  int pv = fpar(v);
  if (pu == pv) return false;
  if (sz[pu] < sz[pv]) swap(pu, pv);
  sz[pu] += sz[pv];
  par[pv] = pu;
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    par[i] = i, sz[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    ev[u] = i, ev[v] = -i;
  }
  int cnt = 0;
  for (int i = 1; i <= 2 * n; i++) {
    if (ev[i] > 0) {
      b[m++] = ev[i];
    } else {
      int v = -ev[i];
      int p = m - 1;
      while (b[p] != v) p--;
      for (int j = p + 1; j < m; j++) {
        cnt++;
        if (!merge(v, b[j])) {
          puts("NO");
          return 0;
        }
        b[j - 1] = b[j];
      }
      m--;
    }
  }
  puts(cnt == n - 1 ? "YES" : "NO");

  return 0;
}
