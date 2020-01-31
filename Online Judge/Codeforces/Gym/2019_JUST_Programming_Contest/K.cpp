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
    map<int, int> mp;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (!mp.count(a[i])) {
        mp[a[i]] = 1;
        ans++;
      }
      for (int j = i - 1; j >= 1; j--) {
        if (a[j] == (a[j] | a[i])) break;
        a[j] = (a[j] | a[i]);
        if (!mp.count(a[j])) {
          mp[a[j]] = 1;
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
