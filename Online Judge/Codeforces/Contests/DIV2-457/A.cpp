cp#include <bits/stdc++.h>

using namespace std;

int x;
int hh, mm;

bool lucky(int x) {
  int curh = x / 60;
  int curm = x % 60;
  while (curh > 0) {
    if (curh % 10 == 7) return true;
    curh /= 10;
  }
  while (curm > 0) {
    if (curm % 10 == 7) return true;
    curm /= 10;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> x >> hh >> mm;
  int tim = hh * 60 + mm;
  int ans = 1e9;
  for (int i = 0; i <= 23 * 60 + 59; i++) {
    int dif = (i <= tim ? tim - i : tim - i + 24 * 60);
    if (dif % x == 0 && lucky(i)) ans = min(ans, dif / x);
  }
  cout << ans << '\n';

  return 0;
}
