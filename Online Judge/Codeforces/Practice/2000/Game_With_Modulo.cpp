#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string inp;
  char r1, r2;
  while (1) {
    cin >> inp;
    if (inp[0] == 'e') exit(0);
    int l = 0, r = INF - 2, ans = 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      cout << mid + 1 << " " << mid << endl;
      cin >> r1;
      if (r1 == 'y') {
        ans = mid;
        r = mid - 1;
        continue;
      }
      cout << mid + 2 << " " << mid + 1 << endl;
      cin >> r2;
      if (r1 == 'y' && r2 == 'x') {
        ans = mid;
        r = mid - 1;
      }
    }
  }

  return 0;
}