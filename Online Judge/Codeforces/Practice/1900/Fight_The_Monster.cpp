#include <bits/stdc++.h>

using namespace std;

int hy, ay, dy;
int hm, am, dm;
int h, a, d;

int ceil(int x, int h) {
  return (x + h - 1) / h;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> hy >> ay >> dy;
  cin >> hm >> am >> dm;
  cin >> h >> a >> d;
  int ans = 2e9;
  for (int j = 0; j <= 200; j++) {
    for (int k = 0; k <= 200; k++) {
      int cay = ay + j, cdy = dy + k;
      if (cay - dm <= 0) continue;
      int i;
      if (am - cdy <= 0) {
        i = 0;
      } else {
        int l = 0, r = 1e9;
        while (l <= r) {
          int mid = (l + r) >> 1;
          if (ceil(hy + mid, am - cdy) > ceil(hm, cay - dm)) {
            i = mid;
            r = mid - 1;
          } else {
            l = mid + 1;
          }
        }
      }
      ans = min(ans, i * h + j * a + k * d);
    }
  }
  cout << ans << '\n';

  return 0;
}
