#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

int n, m, q;
int par[N];

int fpar(int x) {
  return (par[x] == x ? x : par[x] = fpar(par[x]));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> q;
  for (int i = 1; i <= n + m; i++) {
    par[i] = i;
  }
  for (int i = 1; i <= q; i++) {
    int x, y;
    cin >> x >> y;
    int pu = fpar(x), pv = fpar(y + n);
    par[pu] = pv;
  }
  int component = 0;
  for (int i = 1; i <= n + m; i++) {
    if (fpar(i) == i) component++;
  }
  cout << component - 1 << '\n';

  return 0;
}
