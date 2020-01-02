#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;
int n;
char a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  char x;
  int l = 0, d = 0, u = 0, r = 0;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (x == 'L') l++;
    else if (x == 'D') d++;
    else if (x == 'U') u++;
    else if (x == 'R') r++;
  }
  cout << 2 * min(l, r) + 2 * min(d, u) << '\n';

  return 0;
}
