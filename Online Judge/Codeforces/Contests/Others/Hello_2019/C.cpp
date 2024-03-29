#include <bits/stdc++.h>

using namespace std;

const int N = 250000 + 10;

long long n, M;
long long fact[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> M;
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = (i * fact[i - 1]) % M;
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    long long cur = (n - i + 1) * fact[n - i + 1];
    cur = (cur % M + M) % M;
    cur = (cur * fact[i]);
    cur = (cur % M + M) % M;
    ans += cur;
    ans = (ans % M + M) % M;
  }
  cout << (ans % M + M) % M << '\n';

  return 0;
}
