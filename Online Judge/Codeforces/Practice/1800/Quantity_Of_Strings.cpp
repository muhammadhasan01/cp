#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
const int M = 1e9 + 7;

int n, m, k;
int par[N], sz[N];

int fpar(int x) {
  return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
  int pu = fpar(u);
  int pv = fpar(v);
  if (pu == pv) return;
  if (sz[pu] < sz[pv]) swap(pu, pv);
  sz[pu] += sz[pv];
  par[pv] = pu;
}

long long fast(long long x, int y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % M;
    y >>= 1;
    x = (x * x) % M;
  }
  return (res % M + M) % M;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    par[i] = i;
    sz[i] = 1;
  }
  for (int i = 1; i <= n - k + 1; i++) {
    for (int j = 0; j < k / 2; j++) {
      merge(i + j, i + k - j - 1);
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (fpar(i) == i) cnt++;
  }
  cerr << cnt << '\n';
  cout << fast(m, cnt) << '\n';

  return 0;
}
