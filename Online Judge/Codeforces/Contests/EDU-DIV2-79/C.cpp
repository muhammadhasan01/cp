#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int tc;
int n, m;
int a[N], b[N];
long long pos[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pos[a[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
      cin >> b[i];
    }
    long long ans = 2 * (pos[b[1]] - 1) + 1;
    long long sz = 1, r = pos[b[1]];
    for (int i = 2; i <= m; i++) {
      if (pos[b[i]] <= r) {
        ans++;
      } else {
        r = pos[b[i]];
        ans +=  2 * (r - 1 - sz) + 1;
      }
      sz++;
    }
    cout << ans << '\n';
  }

  return 0;
}
