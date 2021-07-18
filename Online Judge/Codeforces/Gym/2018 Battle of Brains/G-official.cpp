#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 100010;
const int MOD = 1e9 + 7;

char s[N];
int t, cs, n;

inline long long sum (long long l, long long r) {
  if (l > r) return 0;
  long long ret = (r * (r + 1) - l * (l - 1)) / 2;
  return ret % MOD;
}

// void brute() {
//   long long ret = 0;
//   for (int l = 1; l <= n; ++l) {
//     for (int i = 1; i <= n - l + 1; ++i) {
//       for (int j = i; j < i + l; ++j) {
//         ret += l * 1LL * s[j];
//         ret %= MOD;
//       }
//     }
//   }
//   cout << ret << endl;
// }

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %s", &n, s + 1);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      long long val = s[i];
      long long one = i * 1LL * sum(i, n) % MOD;
      long long two = (n - i + 1LL) * 1LL * sum(1, i - 1) % MOD;
      long long add = one - two;
      if (add < 0) add += MOD;
      ans = (ans + add * val) % MOD;
    }
    ans %= MOD, ans += MOD, ans %= MOD;
    printf("Case %d: %lld\n", ++cs, ans);
    // brute();
  }
  return 0;
}
