#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
int n, m, k;
char a[N][N];
int ans;

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
  for (int i = 1; i <= n; i++) {
    int c = 0;
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '.') c++;
      else {
        ans += max(0, c - k + 1);
        c = 0;
      }
    }
    ans += max(0, c - k + 1);
  }
  for (int j = 1; j <= m; j++) {
    int c = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i][j] == '.') c++;
      else {
        ans += max(0, c - k + 1);
        c = 0;
      }
    }
    ans += max(0, c - k + 1);
  }
  if (k == 1) ans /= 2;
  cout << ans << '\n';

  return 0;
}
