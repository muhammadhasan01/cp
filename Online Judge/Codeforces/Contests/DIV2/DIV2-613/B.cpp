#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
int n;
int a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n;
    long long sum = 0;
    int c = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum += (1LL) * a[i];
      if (a[i] > 0) c++;
    }
    if (c == n) {
      cout << "YES" << '\n';
      continue;
    }
    long long res = -1e18;
    long long cur = 0;
    for (int i = 1; i <= n - 1; i++) {
      cur += (1LL) * a[i];
      res = max(res, cur);
      if (cur < 0) {
        cur = 0;
      }
    }
    cur = 0;
    for (int i = 2; i <= n; i++) {
      cur += (1LL) * a[i];
      res = max(res, cur);
      if (cur < 0) cur = 0;
    }
    cout << (sum > res ? "YES" : "NO") << '\n';
  }

  return 0;
}
