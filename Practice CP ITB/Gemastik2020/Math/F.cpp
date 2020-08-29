#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int N = 1e6 + 5;
const ll M = 998244353;
ll n;
vector<ll> v[N];
ll len[N];
ll cnt[N];
ll valid, all;
ll ans;
 
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
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> len[i];
    v[i].resize(len[i]);
    for (int j = 0; j < len[i]; j++) {
      cin >> v[i][j];
      cnt[v[i][j]]++;
    }
  }
  ll invn = inv(n);
  for (int i = 1; i <= n; i++) {
    ll invj = inv(len[i]);
    for (int j = 0; j < len[i]; j++) {
      ans = (ans + ((invn * invj) % M) * ((cnt[v[i][j]] * invn) % M)) % M;
    }
  }
  cout << (ans % M + M) % M << '\n';
 
  return 0;
}