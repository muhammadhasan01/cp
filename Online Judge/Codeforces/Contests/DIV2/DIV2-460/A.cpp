#include <bits/stdc++.h>

using namespace std;

int n;
double m;
double a, b;
double ret = 2e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    ret = min(ret, a / b);
  }
  cout << fixed << setprecision(12);
  cout << m * ret << '\n';

  return 0;
}
