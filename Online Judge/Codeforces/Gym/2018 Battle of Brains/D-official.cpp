#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

int t, cs;
long long n, ten[20];

int main() {
  ten[0] = 1;
  for (int i = 1; i < 20; ++i) {
    ten[i] = 10LL * ten[i - 1];
  }
  cin >> t;
  while (t--) {
    scanf("%lld", &n);
    printf("Case %d: ", ++cs);
    int len = 0;
    while (n > ten[len + 1] - ten[len]) {
      n -= (ten[len + 1] - ten[len]);
      ++len;
    }
    if (len == 0) {
      printf("%lld\n", n);
      continue;
    }
    // cout << n << " " << len << endl;
    long long tot = ten[len] - ten[len - 1];
    long long pos = 1 + (n - 1) / 10, mid = (n - 1) % 10;
    long long tmp = ten[len - 1] + pos - 1;
    printf("%lld%lld", tmp, mid);
    for (int i = 0; i < len; ++i) {
      int dig = tmp % 10;
      printf("%d", dig);
      tmp /= 10;
    }
    puts("");
  }
  return 0;
}
