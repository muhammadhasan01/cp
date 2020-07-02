#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int tc;
int n;
long long s;
long long a[N], pre[N], suf[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pre[i] = pre[i - 1] + a[i];
    }
    if (pre[n] <= s) {
      cout << 0 << '\n';
      continue;
    }
    int ans = 0, maks = -1;
    for (int i = 1; i <= n; i++) {
      if (pre[i - 1] > s) break;
      int l = i, r = n, pos = -1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (pre[i - 1] + pre[mid] - pre[i] <= s) {
          pos = mid;
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      if (maks < pos) {
        maks = pos;
        ans = i;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
