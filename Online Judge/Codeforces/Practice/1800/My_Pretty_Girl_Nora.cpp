#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 100;
const long long M = 1e9 + 7;

long long t, l, r;
long long primes[N];
long long dp[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t >> l >> r;
  for (long long i = 2; i < N; i++) {
    if (primes[i] == 0) {
      for (long long j = i; j < N; j += i) {
        primes[j] = i;
      }
    }
  }
  dp[2] = 1;
  for (long long i = 3; i < N; i++) {
    long long j = primes[i];
    if (i == j) {
      dp[i] = j * (j - 1) / 2;
      dp[i] %= M;
    } else {
      dp[i] = (j * dp[i / j]) % M;
      dp[i] = (dp[i] + dp[j]) % M;
    }
  }
  long long cur = 1;
  long long ans = 0;
  for (int i = l; i <= r; i++) {
    ans = (ans + cur * dp[i]) % M;
    cur = (cur * t) % M;
  }
  cout << ans << '\n';

  return 0;
}
