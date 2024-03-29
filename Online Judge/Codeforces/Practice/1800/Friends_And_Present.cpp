#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1e18;
ll c1, c2, x, y;
ll c, z;

bool can(ll k) {
  ll k1 = (k / y) - (k / y) / x;
  ll k2 = (k / x) - (k / x) / y;
  ll k3 = (k / z);
  ll res = k - k1 - k2 - k3;
  ll dif = max(0LL, c1 - k1) + max(0LL, c2 - k2);
  return (res >= dif);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> c1 >> c2 >> x >> y;
  c = c1 + c2;
  z = x * y;
  ll l = 1, r = INF, ans = -1;
  while (l <= r) {
    ll mid = (l + r) >> 1;
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
