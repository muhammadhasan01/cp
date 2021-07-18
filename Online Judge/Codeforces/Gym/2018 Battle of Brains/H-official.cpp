#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 6005;

char s[N];
int t, cs, n, q, cost[N][N];

inline int get (int l, int r) {
  if (l >= r) return 0;
  return cost[l][r];
}

// int brute (int l, int r, int bound) {
//   for (int i = l, j = r; i <= j; ++i, --j) {
//     int cur = 0;
//     for (int k = i, l = j; k < l; ++k, --l) {
//       cur += abs(s[k] - s[l]);
//     }
//     if (cur <= bound) return j - i + 1;
//   }
//   return 0;
// }

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%s %d", s + 1, &q);
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
      int j = 1, last = 0;
      while (i - j > 0 and i + j <= n) {
        cost[i - j][i + j] = last + abs(s[i - j] - s[i + j]);
        last = cost[i - j][i + j]; ++j;
      }
    }
    for (int i = 1; i <= n; ++i) {
      int j = 1, last = 0;
      while (i - j + 1 > 0 and i + j <= n) {
        cost[i - j + 1][i + j] = last + abs(s[i - j + 1] - s[i + j]);
        last = cost[i - j + 1][i + j]; ++j;
      }
    }
    while (q--) {
      int l, r;
      long long bound;
      scanf("%d %d %lld", &l, &r, &bound);
      // cout << brute(l, r, bound) << " ";
      int lo = 0, hi = (r - l + 1) / 2;
      while (lo < hi) {
        int mid = lo + hi >> 1;
        if (get(l + mid, r - mid) > bound) {
          lo = mid + 1;
        } else {
          hi = mid;
        }
      }
      l += lo, r -= lo;
      int ans = max(0, r - l + 1);
      printf("%d\n", ans);
    }
  }
  return 0;
}
