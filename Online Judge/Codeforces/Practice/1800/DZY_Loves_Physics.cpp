#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 5;

int n, m;
int x[N];
double ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    ans = max(ans, 1.0 * (x[u] + x[v]) / w);
  }
  cout << fixed << setprecision(12) << ans << '\n';

  return 0;
}
