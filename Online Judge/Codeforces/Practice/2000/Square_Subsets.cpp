#include <bits/stdc++.h>

using namespace std;

const int N = 70;
const int K = 20;
const long long M = 1e9 + 7;

int n;
int rep[N + 5];
int fre[N + 5];
bool prime[N + 5];
long long dp[2][(1 << K)];

long long fast(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % M;
    y >>= 1;
    x = (x * x) % M;
  }
  return ret;
}

long long get_oddz(int x) {
  if (x == 0) return 0;
  if (x == 1) return 1;
  return fast(2, x - 1);
}

long long get_even(int x) {
  if (x <= 1) return 1;
  return fast(2, x - 1);
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int cnt = 0;
  for (int i = 2; i <= N; i++) {
    if (prime[i] == 0) {
      ++cnt;
      for (int j = i; j <= N; j += i) {
        prime[j] = 1;
        int cur = j;
        int parity = 0;
        while (cur % i == 0) {
          cur /= i;
          parity ^= 1;
        }
        if (parity) rep[j] |= (1 << cnt);
      }
    }    
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    fre[x]++;
  }
  dp[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    long long even = get_even(fre[i]);
    long long oddz = get_oddz(fre[i]);
    long long mask = rep[i];
    int now = (i & 1);
    int bfr = !(i & 1);
    for (int j = 0; j < (1 << K); j++) dp[now][j] = 0LL;
    for (int j = 0; j < (1 << K); j++) {
      dp[now][j] = (dp[now][j] + dp[bfr][j] * even) % M;
      dp[now][(j ^ mask)] = (dp[now][(j ^ mask)] + dp[bfr][j] * oddz) % M;
    }
  }
  cout << ((dp[0][0] - 1) % M + M) % M << '\n';

  return 0; 
}