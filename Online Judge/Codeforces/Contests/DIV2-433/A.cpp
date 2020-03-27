#include <bits/stdc++.h>

using namespace std;

int n;
double d = 0;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  int x = 1, y = n - 1;
  for (int i = 1; i < n; i++) {
    if (i >= n - i) break;
    if (__gcd(i, n - i) > 1) continue;
    double was = d;
    d = max(d, ((1.0) * i / (n - i)));
    if (was != d) {
      x = i, y = n - i;
    }
  }
  cout << x << " " << y << '\n';

  return 0;
}