#include <bits/stdc++.h>

using namespace std;

int a, b, f, k;
int cur;

void dismiss() {
  cout << -1 << '\n';
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> a >> b >> f >> k;
  int res = 0;
  cur = b;
  for (int i = 1; i <= k; i++) {
    if (i == k && cur >= a) continue;
    if (i % 2 == 0) {
      if (cur < a - f) dismiss();
      if (i == k && b < f) dismiss();
      if (cur >= a + f) {
        cur -= a;
      } else {
        res++;
        cur = b - f;
      }
    } else {
      if (cur < f) dismiss();
      if (i == k && b < a - f) dismiss();
      if (cur >= a + (a - f)) {
        cur -= a;
      } else {
        cur = b - (a - f);
        res++;
      }
    }
  }
  cout << res << '\n';

  return 0;
}
