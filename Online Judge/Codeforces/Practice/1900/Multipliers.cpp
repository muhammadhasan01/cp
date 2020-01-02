#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e9 + 7;
ll n;
map<ll, ll> m;
ll prod = 1;

ll fast(ll x, ll y) {
  ll ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % M;
    y >>= 1;
    x = (x * x) % M;
  }
  return (ret % M + M) % M;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    prod = (prod * x) % M;
    m[x]++;
  }

  ll prod1 = 1;

  bool val = false;
  for (auto e : m) {
    ll x = e.second;
    if ((x & 1) && !val) {
      x = (x + 1) / 2 - 1;
      val = true;
    }
    prod1 = (prod1 * (x + 1)) % (M - 1);
  }

  if (!val) {
    prod = 1;
    for (auto e : m) {
      ll x = e.second / 2;
      while (x--) {
        prod = (prod * e.first) % M;
      }
    }
  }

  cout << fast(prod, prod1) << '\n';

  return 0;
}
