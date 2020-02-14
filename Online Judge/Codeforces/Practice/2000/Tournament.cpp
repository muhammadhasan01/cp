#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n;
bool a[N][N];
int deg_in[N], deg_out[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n * (n - 1) / 2 - 1; i++) {
    int u, v;
    cin >> u >> v;
    a[u][v] = 1;
    deg_out[u]++;
    deg_in[v]++;
  }
  int x = -1, y = -1;
  vector<bool> vis(n + 1);
  for (int i = 1; i <= n; i++) {
    if (deg_in[i] + deg_out[i] != n - 1) {
      if (x == -1) x = i;
      else y = i;
    }
    vis[deg_in[i]] = 1;
  }
  int need = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      need = i;
      break;
    }
  }
  if (deg_in[x] + 1 == need) swap(x, y);
  cout << x << " " << y << '\n';

  return 0;
}
