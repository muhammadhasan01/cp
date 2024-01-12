#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll concatenate(ll u, ll v) {
  ll temp = v;
  while (temp > 0) {
    u *= 10LL;
    temp /= 10LL;
  }
  return u + v;
}

ll remove_last(ll u, ll v) {
  while (v > 0) {
    u /= 10LL;
    v /= 10LL;
  }
  return u;
}

bool get_last(ll u, ll v) {
  if (u < v) {
    return 0;
  }
  while (v > 0) {
    if (u % 10LL != v % 10LL) {
      return 0;
    }
    u /= 10LL;
    v /= 10LL;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<ll> list_C = {1,         5,        6,       25,       76,
                       376,       625,      9376,    90625,    109376,
                       890625,    2890625,  7109376, 12890625, 87109376,
                       212890625, 787109376};

  ll N;
  cin >> N;

  for (ll C : list_C) {
    ll a = 1;
    while (1) {
      ll A = concatenate(a, C);
      ll B = concatenate(N, C) / A;
      if (B < A) {
        break;
      }
      if (concatenate(N, C) % A == 0 && concatenate(N, C) % B == 0 &&
          get_last(B, C) && B != C) {
        cout << "YA\n" << remove_last(A, C) << " " << remove_last(B, C) << " "
             << C;
        return 0;
      }
      a++;
    }
  }
  cout << "TIDAK";

  return 0;
}