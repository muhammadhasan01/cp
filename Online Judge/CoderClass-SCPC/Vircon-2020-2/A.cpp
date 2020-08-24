#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll R, S;
  cin >> R >> S;
  ll G = __gcd(R, S);
  R /= G, S /= G;
  ll ans = 0;
  for(int i = S; i < R; i += S) {
    ld can = (ld)(2.0) * sqrtl(((ld)R) * ((ld)R) - ((ld)i) * ((ld)i));
    ld lul = can / (ld)(S);
    ans += (ll) (floorl(lul));
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}