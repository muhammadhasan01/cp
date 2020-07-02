#include <bits/stdc++.h>

using namespace std;



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int a, b;
  cin >> a >> b;
  int res = (a | b) - b;
  cout << res << '\n';

  return 0;
}
