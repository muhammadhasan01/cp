#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const long long INF = 1e16;

int n;
bool r[N], b[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> r[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  long long x = 0, y = 0;
  for (int i = 1; i <= n; i++) {
    if (r[i] && !b[i]) {
      x++;
    } else if (!r[i] && b[i]) {
      y++;
    }
  }
  long long l = 0, r = INF, at = -1;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (x * mid > y) {
      at = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << at << '\n';

  return 0;
}