#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll calc(int x) {
  return 1LL * (x + 2) * (x + 1) / 2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    int n, m, x;
    cin >> n >> m >> x;
    x--;
    ll ans;
    if(x < n && x < m) {
      ans = calc(x);
    } else if(x < n) {
      ans = calc(x) - calc(x - m);
    } else if(x < m) {
      ans = calc(x) - calc(x - n);
    } else if(m + n > x) {
      ans = calc(x) - calc(x - m) - calc(x - n);
    } else {
      ans = 1LL * m * n;
    }
    cout << ans << '\n';
  }
  return 0;