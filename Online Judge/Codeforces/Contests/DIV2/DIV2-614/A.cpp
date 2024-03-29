#include <bits/stdc++.h>

using namespace std;

const int K = 1e3 + 5;

int tc;
long long n, s, k;
int a[K];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while (tc--) {
    cin >> n >> s >> k;
    map<int, int> mp;
    for (int i = 1; i <= k; i++) {
      cin >> a[i];
      mp[a[i]] = 1;
    }
    int ans = 1e9;
    for (int i = 0; i <= 2 * k + 5; i++) {
      if (s + i <= n && mp[s + i] == 0) {
        ans = i;
        break;
      }
      if (s - i >= 1 && mp[s - i] == 0) {
        ans = i;
        break;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
