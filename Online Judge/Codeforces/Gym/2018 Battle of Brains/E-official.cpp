#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

int t, cs, d;
long long x;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %lld", &d, &x);
    printf("Case %d: ", ++cs);
    if (x == 0) {
      puts("YES 0");
      continue;
    }
    int bad = 1, ans = 1;
    long long at = 0;
    for (int i = d; i >= 0; --i, ++ans) {
      if (at > x and at >= (1LL << i)) at -= (1LL << i);
      else at += (1LL << i);
      if (at == x) {
        bad = 0;
        printf("YES %d\n", ans);
        break;
      }
    }
    if (bad) puts("NO");
  }
  return 0;
}
