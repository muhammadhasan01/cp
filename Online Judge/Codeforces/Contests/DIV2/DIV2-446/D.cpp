#include <bits/stdc++.h>

using namespace std;

const int N = 23;

int n;
int org[N];
int a[N], ans[N];
map<int, int> mp;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    org[i] = a[i];
  }
  if (n == 1) {
    cout << a[1] << '\n';
    return 0;
  } else if (n == 2) {
    cout << a[2] << " " << a[1] << '\n';
    return 0;
  }
  sort(a + 1, a + 1 + n);
  mp[a[1]] = a[n];
  for (int i = 2; i <= n; i++) {
    mp[a[i]] = a[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    ans[i] = mp[org[i]];
  }
  for (int i = 1; i < (1 << n) - 1; i++) {
    long long sum = 0;
    for (int j = 0; j < n; j++) {
      bool b = (i & (1 << j));
      if (b) {
        sum += (1LL) * (org[j + 1] - ans[j + 1]);
      }
    }
    if (sum == 0) {
      cout << -1 << '\n';
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}