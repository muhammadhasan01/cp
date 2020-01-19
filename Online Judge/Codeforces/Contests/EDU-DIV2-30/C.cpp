#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n, m, k;
bool a[N][N];
int pre[N][N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      pre[i][j] = pre[i - 1][j];
      if (a[i][j]) pre[i][j]++;
    }
  }
  int ans = 0, res = 0;
  for (int j = 1; j <= m; j++) {
    int curans = 0, curres = 0;
    int oc = -1;
    for (int i = 1; i <= n; i++) {
      if (a[i][j]) {
        int cur = pre[min(i + k - 1, n)][j] - pre[i - 1][j];
        oc++;
        if (cur > curans) {
          curans = cur;
          curres = oc;
        }
      }
    }
    ans += curans;
    res += curres;
  }
  cout << ans << " " << res << '\n';

  return 0;
}
