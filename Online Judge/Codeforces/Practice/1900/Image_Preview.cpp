#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e5 + 5;

int n;
ll a, b, T;
ll pre[N], suf[N];
string s;

bool can(ll x) {
  if (x == 1) return (pre[1] + x <= T);
  if (x == 2) {
    ll cur = pre[2] + a + x;
    cur = min(cur, suf[n] + a + x);
    return (cur <= T);
  }
  ll cur;
  for (ll i = x; i >= 0; i--) {
    ll j = x - i;
    if (i == x) {
      cur = pre[x] + (x - 1) * a + x;
    } else if (i == 0) {
      cur = suf[n - x + 1] + (x - 1) * a + x;
    } else {
      cur = pre[i] + suf[n - j + 1]  - pre[1] + (2 * (i - 1) + j) * a + x;
      cur = min(cur, pre[i] + suf[n - j + 1]  - pre[1] + (i - 1 + 2 * j) * a + x);
    }
    if (cur <= T) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> a >> b >> T;
  cin >> s;
  s = '#' + s + s[0];
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + (s[i] == 'w' ? b : 0);
  }
  for (int i = n + 1; i >= 1; i--) {
    suf[i] = suf[i + 1] + (s[i] == 'w' ? b : 0);
  }
  int l = 1, r = n, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (can(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ans << '\n';

  return 0;
}
