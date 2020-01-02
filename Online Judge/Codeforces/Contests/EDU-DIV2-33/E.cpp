#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int q;
ll x, y;

const int N = 1e6 + 100;
const ll M = 1e9 + 7;
ll fact[N];
ll invf[N];
ll prime[N];

ll egcd(ll a, ll b, ll &x, ll &y) {
  if (a == 0) {
    x = 0, y = 1;
    return b;
  }
  ll x1, y1;
  ll d = egcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}

ll inv(ll k) {
  ll x, y;
  egcd(k, M, x, y);
  return (x % M + M) % M;
}

ll C(int a, int b) {
  ll ret = fact[a] * invf[a - b];
  ret = (ret % M + M) % M;
  ret = (ret * invf[b]);
  return (ret % M + M) % M;
}

ll fast(ll x, ll y) {
  ll ret = 1;
  while (y) {
    if (y & 1) {
      ret = (ret * x);
      ret = (ret % M + M) % M;
    }
    y >>= 1;
    x = (x * x);
    x = (x % M + M) % M;
  }
  return (ret % M + M) % M;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  fact[0] = invf[0] = 1;
  for (ll i = 1; i <= N - 5; i++) {
    fact[i] = (i * fact[i - 1]) % M;
    fact[i] = (fact[i] % M + M) % M;
    invf[i] = (invf[i - 1] * inv(i)) % M;
    invf[i] = (invf[i] % M + M) % M;
  }

  prime[1] = 1;
  for (ll i = 2; i <= N - 5; i++) {
    if (prime[i] == 0) {
      for (ll j = i; j <= N - 5; j += i) {
        prime[j] = i;
      }
    }
  }

  cin >> q;
  while (q--) {
    cin >> x >> y;
    ll res = 1;
    while (prime[x] > 1) {
      ll k = prime[x];
      int c = 0;
      while (x % k == 0) {
        x /= k;
        c++;
      }
      res = (res * C(c + y - 1, y - 1));
      res = (res % M + M) % M;
    }
    res = (res * fast(2, y - 1)) % M;
    cout << (res % M + M) % M << '\n';
  }

  return 0;
}
