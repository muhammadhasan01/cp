#include <bits/stdc++.h>

using namespace std;

int n;
int a, b, c, d;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  cout << "YES" << '\n';
  for (int i = 1; i <= n; i++) {
    cin >> a >> b >> c >> d;
    cout << ((12 + 2 * (a % 2) + (b % 2)) % 4) + 1 << '\n';
  }

  return 0;
}