#include <bits/stdc++.h>

using namespace std;

const int N = 305;
const int INF = 1e9;
int n;
int l[N], c[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    for (auto e : mp) {
      int g = __gcd(l[i], e.first);
      if (g < e.first) {
        if (!mp.count(g)) {
          mp[g] = INF;
        }
        mp[g] = min(mp[g], e.second + c[i]);
      }
    }
    if (!mp.count(l[i])) {
      mp[l[i]] = INF;
    }
    mp[l[i]] = min(mp[l[i]], c[i]);
  }
  if (!mp.count(1)) {
    cout << -1 << '\n';
    return 0;
  }
  cout << mp[1] << '\n';

  return 0;
}
