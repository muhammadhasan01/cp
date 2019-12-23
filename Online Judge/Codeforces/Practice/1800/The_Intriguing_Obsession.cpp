#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int M = 998244353;
const int N = 5e3 + 5;
int a, b, c;
ll f[N], in[N], ans;

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

ll inv(ll a) {
  ll x, y;
  egcd(a, M, x, y);
  return (x % M + M) % M;
}

ll C(int a, int b) {
  if (b > a) return 0;
  ll ret = (f[a] * in[b]) % M;
  ret = (ret * in[a - b]) % M;
  return ret;
}

ll solve(ll a, ll b) {
  ll ret = 0;
  for (int i = 0; i <= min(a, b); i++) {
    ll cur = 1;
    cur = (cur * f[i]) % M;
    cur = (cur * C(a, i)) % M;
    cur = (cur * C(b, i)) % M;
    ret = (ret + cur) % M;
   }
   return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> a >> b >> c;
  f[0] = in[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = (f[i - 1] * (1LL) * i) % M;
    in[i] = inv(f[i]);
  }
  ans = (solve(a, b) * solve(b, c)) % M;
  ans = (ans * solve(c, a)) % M;
  cout << (ans % M + M) % M << '\n';

  return 0;
}
