#include <bits/stdc++.h>

using namespace std;

const long long M = 1e9 + 7;
const int N = 1e6 + 5;

long long p, k;
bool vis[N];

long long fast(long long x, long long y, long long z) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % z;
    y >>= 1;
    x = (x * x) % z;
  }
  return ret;
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> p >> k;
  if (k == 0) {
    cout << fast(p, p - 1, M) << '\n';
    return 0;
  }
  long long ans = 1;
  for (int i = 0; i < p; i++) {
    if (vis[i]) continue;
    int sz = 0;
    int cur = i;
    while (!vis[cur]) {
      vis[cur] = 1;
      sz++;
      cur = (k * cur) % p;
    }
    long long val = fast(k, sz, p) - 1;
    if (val == 0) {
      ans = (ans * p) % M;
    } else if (p % val == 0 && val > 1) {
      ans = (ans * 2) % M;
    }
  }
  cout << ans << '\n';

  return 0;
}