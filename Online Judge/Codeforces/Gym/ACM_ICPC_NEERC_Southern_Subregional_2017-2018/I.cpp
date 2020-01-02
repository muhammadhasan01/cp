#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 3e5 + 5;
int n, k;
int a[N];
bool vis[N];

bool can(int x) {
  for (int i = 0; i <= n; i++) vis[i] = 0;
  vis[0] = 1;
  for (int i = 1, pos = k; i <= n - k + 1; i++) {
    if (!vis[i - 1]) continue;
    while (pos < min(n, i + k - 1)) pos++;
    while (pos <= n && a[pos] - a[i] <= x) vis[pos++] = 1;
  }
  return vis[n];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  int l = 0, r = INF, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (can(mid)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';

  return 0;
}
