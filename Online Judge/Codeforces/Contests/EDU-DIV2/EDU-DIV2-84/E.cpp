#include <bits/stdc++.h>

using namespace std;

const long long M = 998244353;
const int N = 2e5 + 5;

long long n;
long long pre[N];
long long ans[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  pre[0] = 1;
  for (int i = 1; i < N; i++) {
    pre[i] = (10 * pre[i - 1]) % M;
  }
  cin >> n;
  if (n == 1) {
    cout << 10 << '\n';
  } else if (n == 2) {
    cout << 180 << " " << 10 << '\n';
  } else {
    ans[n] = 10;
    ans[n - 1] = 180;
    for (int i = n - 2; i >= 1; i--) {
      ans[i] = ((1LL) * 180 * pre[n - i - 1]) % M;
      long long cur = ((1LL) * 81 * pre[n - i - 2]) % M;
      cur = (cur * (n - i - 1)) % M;
      cur = (cur * 10) % M;
      ans[i] = (ans[i] + cur) % M;
    } 
    for (int i = 1; i <= n; i++) {
      cout << (ans[i] % M + M) % M << (i == n ? '\n' : ' ');
    }
  }

  return 0;
}